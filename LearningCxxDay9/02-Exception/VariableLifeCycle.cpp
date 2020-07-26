#include<iostream>
using namespace std;

/**
 * 03  异常变量生命周期
 */

class MyException
{
public:
    MyException()
    {
        cout << "MyException默认构造函数调用" << endl;
    }

    MyException(const MyException & e)
    {
        cout << "MyException拷贝构造函数调用" << endl;
    }

    ~MyException()
    {
        cout << "MyException析构函数调用" << endl;
    }
};

void doWork()
{
    throw  new MyException();
}

/**
 * 抛出的是 throw &MyException(); catch (MyException *e) 对象会提前释放掉，不能再非法操作
 * 原因：匿名对象，doWork函数执行完，就释放了；   *e 指针指向了非法地址；
 *
 *
 * 抛出的是 throw MyException();  catch (MyException &e)  只调用默认构造函数 效率高 推荐    用这种就可以！
 * 问题：throw MyException()也是一个匿名对象，为什么这里不会释放？
 * 原因：MyException &e = MyException()，匿名对象作为右值的时候，相当于起了名字，此时声明周期就和左值相同了，不会提前释放！
 * 注意：指针不等同于起名字！
 */
void test01()
{
    try
    {
        doWork();
    }
        //抛出的是 throw MyException();  catch (MyException e)  调用拷贝构造函数！ 效率低！
        //抛出的是 throw MyException();  catch (MyException &e)  只调用默认构造函数 效率高 推荐    用这种就可以！
        //抛出的是 throw &MyException(); catch (MyException *e) 对象会提前释放掉，不能再非法操作
        //抛出的是 new MyException();   catch (MyException *e) 只调用默认构造函数 自己要管理释放
    catch (MyException *e)
    {
        cout << "自定义异常捕获" << endl;
        delete e;  //需要手动释放！
    }
}

int main(){
    test01();

    return EXIT_SUCCESS;
}