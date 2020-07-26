#include<iostream>
using namespace std;
#include <stdexcept> //  std 标准  except 异常

/**
 * 05  系统提供的标准异常！
 */

class Person
{
public:
    Person(int age)
    {
        if (age < 0 || age > 150)
        {
            throw out_of_range("年龄必须在 0 ~ 150之间");
            //throw length_error("年龄必须在 0 ~ 150之间");
        }
        else
        {
            this->m_Age = age;
        }
    }

    int m_Age;
};

void test01()
{
    try
    {
        Person p(151);
    }
        //catch ( out_of_range &e)
    catch ( exception &e)
    {
        cout << e.what() << endl;
    }
}

int main(){
    test01();

    return EXIT_SUCCESS;
}