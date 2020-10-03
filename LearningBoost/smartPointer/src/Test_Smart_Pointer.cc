#include <boost/scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <boost/shared_ptr.hpp>
#include <vector>
#include <boost/shared_array.hpp>
#include <iostream>
#include <boost/ptr_container/ptr_vector.hpp>

/**
 * 作用域指针：一个作用域指针不能传递它所包含的对象的所有权到另一个作用域指针。只是简单保存和独占一个内存地址。
 * boost::scoped_ptr 的析构函数中使用 delete 操作符来释放所包含的对象。 这对 boost::scoped_ptr 所包含的类型加上了一条重要的限制。 
 * boost::scoped_ptr 不能用动态分配的数组来做初始化，因为这需要调用 delete[] 来释放。 在这种情况下，可以使用下面将要介绍的 boost:scoped_array 类。
 */

void test1() 
{ 
  boost::scoped_ptr<int> i(new int); 
  *i = 1; 
  *i.get() = 2;    //get()返回所含对象的地址
  i.reset(new int);  //但可以指向另外的地址
}

/*
 * 作用域数组的使用方式与作用域指针相似。 关键不同在于，作用域数组的析构函数使用 delete[] 操作符来释放所包含的对象。 因为该操作符只能用于数组对象，所以作用域数组必须通过动态分配的数组来初始化。
 */

int test2() 
{ 
  boost::scoped_array<int> i(new int[2]); 
  *i.get() = 1; 
  i[1] = 2; 
  i.reset(new int[3]); 
} 

/*
 * 共享指针：使用率最高的指针
 * 智能指针 boost::shared_ptr 基本上类似于 boost::scoped_ptr。 关键不同之处在于 boost::shared_ptr 不一定要独占一个对象。
 * 它可以和其他 boost::shared_ptr 类型的智能指针共享所有权。 在这种情况下，当引用对象的最后一个智能指针销毁后，对象才会被释放。
 * 多亏了有 boost::shared_ptr，我们才能像上例中展示的那样，在标准容器中安全的使用动态分配的对象。 因为 boost::shared_ptr 能够共享它所含对象的所有权，
 * 所以保存在容器中的拷贝（包括容器在需要时额外创建的拷贝）都是和原件相同的
 * 不能在标准容器中存储 std::auto_ptr，因为它们在拷贝的时候传递了所有权，说明原来的指向就失效了！
 */

int test3() 
{
    std::vector<boost::shared_ptr<int> > v; 
    v.push_back(boost::shared_ptr<int>(new int(1))); 
    v.push_back(boost::shared_ptr<int>(new int(2))); 

    //std::shared_ptr和boost中的一样。
    std::vector<std::shared_ptr<int>> v1;
    v1.push_back(std::shared_ptr<int>(new int(1)));
    v1.push_back(std::shared_ptr<int>(new int(2)));

    boost::shared_ptr<int> i1(new int(1)); 
    boost::shared_ptr<int> i2(i1);      //i1和i2指向相同的int值。（拷贝构造）
    i1.reset(new int(2));       //i1指向另外的地址，不过它之前所包含的对象并没有被释放，因为 i2 仍然引用着它

    //默认情况下，boost::shared_ptr 使用 delete 操作符来销毁所含的对象。 然而，具体通过什么方法来销毁，是可以指定的，就像下面的例子里所展示的：
    //boost::shared_ptr<void> h(OpenProcess(PROCESS_SET_INFORMATION, FALSE, GetCurrentProcessId()), CloseHandle);  //boost::shared_ptr 的构造函数的第二个参数是一个普通函数或者函数对象，该参数用来销毁所含的对象;
    //SetPriorityClass(h.get(), HIGH_PRIORITY_CLASS); 
}

/*
 * 共享数组：共享数组的行为类似于共享指针。 关键不同在于共享数组在析构时，默认使用 delete[] 操作符来释放所含的对象。 因为这个操作符只能用于数组对象，共享数组必须通过动态分配的数组的地址来初始化。
 */

int test4() 
{ 
  boost::shared_array<int> i1(new int[2]); 
  boost::shared_array<int> i2(i1); 
  i1[0] = 1;
  std::cout << i2[0] << std::endl; 
}

/*
 * 弱指针！
 * 弱指针只有在配合共享指针一起使用时才有意义！
 * 当函数需要一个由共享指针所管理的对象，而这个对象的生存期又不依赖于这个函数时，就可以使用弱指针。 只要程序中还有一个共享指针掌管着这个对象，函数就可以使用该对象。 如果共享指针复位了，就算函数里能得到一个共享指针，对象也不存在了。
 */

/*
DWORD WINAPI reset(LPVOID p)   //传递的是共享指针
{ 
  boost::shared_ptr<int> *sh = static_cast<boost::shared_ptr<int>*>(p); 
  sh->reset(); 
  return 0; 
} 

DWORD WINAPI print(LPVOID p)   //传递的是弱指针
{ 
  boost::weak_ptr<int> *w = static_cast<boost::weak_ptr<int>*>(p); 
  boost::shared_ptr<int> sh = w->lock();   //lock() 返回一个共享指针。 所以这里起名叫lock()的原因就是要先锁住，先copy出来一个新的共享指针，然后再让原来的 reset()，如果锁住之前已经reset了，直接返回
  if (sh) 
    std::cout << *sh << std::endl; 
  return 0; 
} 

//一旦程序启动之后，reset() 和 print() 就都开始执行了。 不过执行顺序是不确定的。 这就导致了一个潜在的问题：reset() 线程在销毁对象的时候print() 线程可能正在访问它。
//通过调用弱指针的 lock() 函数可以解决这个问题：如果对象存在，那么 lock() 函数返回的共享指针指向这个合法的对象。否则，返回的共享指针被设置为0，这等价于标准的null指针。
//弱指针本身对于对象的生存期没有任何影响。 lock() 返回一个共享指针，print() 函数就可以安全的访问对象了。 这就保证了——即使另一个线程要释放对象——由于我们有返回的共享指针，对象依然存在。
int main() 
{
  boost::shared_ptr<int> sh(new int(99));   //创建了一个共享指针；
  boost::weak_ptr<int> w(sh);               //然后用共享指针初始化了一个弱指针；
  HANDLE threads[2];                        
  threads[0] = CreateThread(0, 0, reset, &sh, 0, 0); 
  threads[1] = CreateThread(0, 0, print, &w, 0, 0); 
  WaitForMultipleObjects(2, threads, TRUE, INFINITE); 
}
*/


/*
 * 指针容器
 */

//一般用法
int test5()
{ 
  std::vector<boost::shared_ptr<int> > v; 
  v.push_back(boost::shared_ptr<int>(new int(1))); 
  v.push_back(boost::shared_ptr<int>(new int(2))); 
}

//优化
int test6()
{
    //boost::ptr_vector 独占它所包含的对象，因而容器之外的共享指针不能共享所有权；
    //除了 boost::ptr_vector 之外，专门用于管理动态分配对象的容器还包括：boost::ptr_deque， boost::ptr_list， boost::ptr_set， boost::ptr_map， boost::ptr_unordered_set 和 boost::ptr_unordered_map
    boost::ptr_vector<int> v;
    v.push_back(new int(1)); 
    v.push_back(new int(2)); 
}