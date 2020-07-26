#include<iostream>
using namespace std;
#include <string>

/**
 * 02 异常接口声明
 */


//声明只允许抛出int类型异常！
void func() throw(int)
{
    throw 1;
    //throw 3.14  //错误
}

int main(){

    try{
        func();
    }
    catch (int)
    {
        cout << "int类型异常" << endl;
    }

    return EXIT_SUCCESS;
}