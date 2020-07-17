#include<iostream>
#include <string>
using namespace std;


class Printer
{
public:
    static Printer * getInstance()
    {
        return printer;
    }

    void printText(string text)
    {
        m_Count++;
        cout << text << endl;
    }

    int m_Count;

private:

    Printer()
    {
        m_Count = 0;
        //cout << "打印机构造调用" << endl;
    };

    Printer(const Printer & p){};

    static Printer * printer;
};

Printer * Printer::printer = new Printer;

void test01()
{
    Printer * p1 = Printer::getInstance();
    p1->printText("入职证明");
    p1->printText("离职证明");
    p1->printText("加薪申请");
    p1->printText("旅游申请");

    cout << "打印机使用次数： " << p1->m_Count << endl;

    Printer * p2 = Printer::getInstance();
    p2->printText("调休申请");

    cout << "打印机使用次数： " << p1->m_Count << endl;

}

int main(){
//	cout << "mian函数调用" << endl;

    test01();

    return EXIT_SUCCESS;
}