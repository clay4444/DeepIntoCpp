#include<iostream>
using namespace std;

namespace KingGlory
{
    int sunwukongId = 1;
}

namespace LOL
{
    int sunwukongId = 3;
}

void test01()
{
    int sunwukongId = 2;

    //1、using 声明 使用KingGlory这个namespace下的sunwukongId
    //using KingGlory::sunwukongId;

    //当using声明与 就近原则同时出现，出错，尽量避免
    cout << sunwukongId << endl;
}

void test02()
{
    //int sunwukongId = 2;
    //2、using编译指令
    using namespace KingGlory;
    using namespace LOL;
    //当using编译指令  与 就近原则同时出现，优先 使用就近!
    //当using编译指令有多个，需要加作用域 区分
    cout << KingGlory::sunwukongId << endl;
    cout << LOL::sunwukongId << endl;
}

int main(){

    //test01();
    test02();
    return EXIT_SUCCESS;
}