#include<iostream>
using namespace std;

/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
void test01()
{
    //输入  a  s     第一次 a  第二次  s  第三次 换行  第四次 等待下次输入
    char c = cin.get();

    cout << "c = " << c << endl;

    c = cin.get();

    cout << "c = " << c << endl;

    c = cin.get();

    cout << "c = " << c << endl;


    c = cin.get();

    cout << "c = " << c << endl;
}


void test02()
{
    char buf[1024] = { 0 };
    cin.get(buf, 1024);

    char c = cin.get();
    //利用cin.get获取字符串时候，换行符遗留在缓冲区中！
    if (  c== '\n')
    {
        cout << "换行符遗留在缓冲区" << endl;
    }
    else
    {
        cout << "换行符不在缓冲区" << endl;
    }
    cout << buf << endl;

}

void test03()
{
    char buf[1024] = { 0 };

    //利用cin.getline获取字符串时候，换行符不会被取走，也不在缓冲区中，而是直接扔掉！
    cin.getline(buf, 1024);

    char c = cin.get();
    if (c == '\n')
    {
        cout << "换行符遗留在缓冲区" << endl;
    }
    else
    {
        cout << "换行符不在缓冲区" << endl;
    }
    cout << buf << endl;

}

//cin.ignore() 忽略 默认忽略1个字符， 如果填入参数X，代表忽略X个字符
void test04()
{
    cin.ignore(2);
    char c = cin.get();
    cout << "c = " << c << endl;
}

//cin.peek() 偷窥
void test05()
{
    char c = cin.peek();
    cout << "c = " << c << endl;

    c = cin.get();
    cout << "c = " << c << endl;

    c = cin.get();
    cout << "c = " << c << endl;

}

//cin.putback() 放回
void test06()
{
    char c = cin.get();
    cin.putback(c);  //放回原来的位置

    char buf[1024] = { 0 };

    cin.getline(buf, 1024);
    cout << buf << endl;
}


//案例1、 判断用户输入的内容 是字符串还是数字  12345     abcde
void test07()
{
    cout << "请输入一个字符串或者数字" << endl;
    char c = cin.peek();

    if (c >= '0' && c <= '9')
    {
        int num;
        cin >> num; // >> 把缓冲区中的数字读走，赋给num！
        cout << "您输入的是数字 为：" << num << endl;
    }
    else
    {
        char buf[1024] = { 0 };
        cin >> buf;  //赋值给buf
        cout << "您输入的是字符串 ：" << buf << endl;
    }
}

//案例2、 用户输入 0 ~ 10 之间的数字，如果输入有误，重新输入
void test08()
{
    cout << "请输入 0 ~ 10 之间的数字" << endl;

    int num;

    while (true)
    {
        cin >> num;  //直接赋值给num

        if (num >= 0 && num <= 10)
        {
            cout << "输入正确，输入值为：" << num << endl;
            break;
        }

        //清空缓冲区 重置标志位
        cin.clear();
        cin.sync();
        //cin.ignore();//vs2013以上版本加入
        //如果标志位为 0  代表缓冲区正常    如果标志位为1   缓冲区异常！    如果输入的是字符串， 就会出现缓冲区异常！ 此时就会死循环！
        cout << " cin.fail()  = " << cin.fail() << endl;

        cout << "输入有误，请重新输入： " << endl;
    }
}

int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    test08();

    return EXIT_SUCCESS;
}