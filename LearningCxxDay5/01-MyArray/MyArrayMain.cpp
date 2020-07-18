#include<iostream>
using namespace std;
#include "myArray.h"

void test01()
{
    MyArray arr;

    for (int i = 0; i < 10;i++)
    {
        arr.pushBack(i);
    }

    for (int i = 0; i < arr.getSize(); i ++)
    {
        cout << arr.getData(i) << endl;
    }

    MyArray arr2(arr);
    for (int i = 0; i < arr2.getSize(); i++)
    {
        cout << arr2.getData(i) << endl;
    }

    arr.setData(0, 1000);

    cout << "arr 0号位置数据为： " << arr.getData(0) << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr.getData(i) << endl;
    }

    cout << "数组容量为： " << arr.getCapcity() << endl;
    cout << "数组大小为： " << arr.getSize() << endl;

    //小任务： 利用[]方式去索引数组中的元素，可读可写
    cout << "---------------------" << endl;

    arr[0] = 10000;
    cout << arr[0] << endl;

}

int main(){
    test01();

    return EXIT_SUCCESS;
}