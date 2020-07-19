#include<iostream>
using namespace std;

/**
 * 02-泛型排序！
 */

template <class T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

//需求 通过一个通用排序函数  实现对char和int数组的排序，排序顺序 从大到小， 算法  选择排序
template< class  T > // typename 和 class 一样！
void mySort( T arr[] , int len)
{
    for (int i = 0; i < len;i++)
    {
        int max = i;
        for (int j = i + 1; j < len;j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }

        //判断 算出的max和开始认定的i是否一致，如果不同交换数据
        if (i != max)
        {
            mySwap(arr[i], arr[max]);
        }
    }

}

template<class T>
void printArray(T arr[] , int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << arr[i] << endl;
    }
}

void test01()
{
    char charArray[] = "helloworld";

    int len = strlen(charArray);
    mySort(charArray, len);

//	printArray(charArray, len);

    int intArray[] = { 5, 7, 1, 4, 2, 3 };
    len = sizeof(intArray) / sizeof(int);
    mySort(intArray, len);
    printArray(intArray, len);
}

int main(){
    test01();

    return EXIT_SUCCESS;
}