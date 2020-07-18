#include<iostream>
using namespace std;

class MyInter
{
    friend ostream& operator<<(ostream& cout, MyInter& myInt);
public:
    MyInter()
    {
        m_Num = 0;
    }

    /**
     * 前置++ 重载
     * @return  MyInter& 引用； 目的：链式编程，可以一直往前++
     */
    MyInter& operator++()
    {
        this->m_Num++;
        return *this;
    }

    /**
     * 后置++ 重载， int是占位参数，加上这个占位参数，就代表是重载的 后置++
     * @return 返回的是值 MyInter！ 也就是说调用默认构造器新创建的对象，而不是引用，引用相当于返回了this
     */
    MyInter operator++(int)
    {
        //先记录初始状态
        MyInter temp = *this;
        this->m_Num++;
        return temp; //返回初始值
    }

private:
    int m_Num;
};

/**
 * << 运算符重载
 */
ostream& operator<<(ostream& cout , MyInter& myInt)
{
    cout << myInt.m_Num;
    return cout;
}

void test01()
{
    MyInter myInt;
    cout << ++(++myInt) << endl;  //2
    cout << myInt << endl;  //2
}

void test02()
{
    MyInter myInt;

    //cout << myInt++ << endl;    //报错原因：myInt++返回的是一个值，而我们已经重写了MyInter的<<的运算符！
    cout << myInt << endl;
}

int main(){
    //test01();
    test02();

    //int a = 0;
    //cout << ++(++a) << endl;  //内置的可以一直调用前置++！
    //cout << a << endl;

    //int b = 0;
    //cout << (b++)++ << endl; //error (b++)返回的也是一个值，不是引用，不能继续调用++！

    return EXIT_SUCCESS;
}