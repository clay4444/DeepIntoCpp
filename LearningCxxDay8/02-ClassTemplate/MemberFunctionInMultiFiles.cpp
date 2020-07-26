using namespace std;
#include "person.hpp"
#include <string>

/**
 * 06 类模板中的成员函数分文件编写
 *
 * 问题：类模板中的成员函数，不会一开始就创建，因此导致分文件编写时连接不到函数的实现，出现无法解析的外部命令错误！
 * 解决方式：
 * 1.直接包含cpp文件
 * 2.类声明和实现写到同一个文件，文件的后缀名改为 .hpp 即可
 */

void test01()
{
    Person<string, int> P("Jerry", 20);
    P.showPerson();
}


int main(){
    test01();

    return EXIT_SUCCESS;
}