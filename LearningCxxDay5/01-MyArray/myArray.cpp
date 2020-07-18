#include "myArray.h"

MyArray::MyArray()
{
    cout << "默认构造函数调用" << endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity)
{
    cout << "有参构造函数调用" << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

/**
 * 覆盖拷贝构造函数，默认拷贝构造函数对堆区的数据只会拷贝地址，是浅拷贝
 * @param arr
 */
MyArray::MyArray(const MyArray & arr)
{
    cout << "拷贝构造函数调用" << endl;
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    //this->pAddress = arr.pAddress;

    this->pAddress = new int[arr.m_Capacity];

    for (int i = 0; i < m_Size;i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }

}

//尾插法
void MyArray::pushBack(int val)
{
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
}

//根据位置设置数据
void MyArray::setData(int pos, int val)
{
    this->pAddress[pos] = val;
}

//根据位置获取数据
int MyArray::getData(int pos)
{
    return this->pAddress[pos];
}

//获取数组容量
int MyArray::getCapcity()
{
    return this->m_Capacity;
}

//获取数组大小
int MyArray::getSize()
{
    return this->m_Size;
}

//析构
MyArray::~MyArray()
{
    if (this->pAddress != NULL)
    {
        cout << "析构函数调用" << endl;
        delete [] this->pAddress;  //释放堆区数组空间！
        this->pAddress = NULL;
    }
}

int& MyArray::operator[](int index)
{
    return this->pAddress[index];
}
