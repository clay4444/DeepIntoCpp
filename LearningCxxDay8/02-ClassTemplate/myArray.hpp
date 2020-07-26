#pragma  once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:
    //MyArray(){};

    //有参构造
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity];  //在堆区开辟数组，一定会调用默认构造；
    }

    //拷贝构造
    MyArray(const MyArray & arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < arr.m_Size;i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    //重载=
    MyArray& operator=( const MyArray & arr)
    {
        if (this->pAddress)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }

        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for (int i = 0; i < arr.m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
        return *this;
    }


    //重载[]
    T& operator[] (int index)
    {
        return this->pAddress[index];
    }

    //尾插法
    void pushBack(const T&val)
    {
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    //获取数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }

    //获取数组大小
    int getSize()
    {
        return this->m_Size;
    }

    //析构
    ~MyArray()
    {
        if (this->pAddress)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T * pAddress; //指向堆区真实数组指针

    int m_Capacity; //数组容量

    int m_Size;  //数组大小

};
