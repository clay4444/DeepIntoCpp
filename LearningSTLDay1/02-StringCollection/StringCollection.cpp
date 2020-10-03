#include<iostream>
using namespace std;
#include <string>
#include <vector>
/*
3.1.2.1 string 构造函数
string();//创建一个空的字符串 例如: string str;
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化

3.1.2.2 string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void test01()
{
    string str;
    string str2(str);

    string str3 = "abc";

    string str4(10, 'a');

    cout << "str3 = " << str3 << endl;

    cout << "str4 = " << str4 << endl;

}
//赋值
void test02()
{
    string  str;
    str = "abc";

    str.assign("abcde", 3);

    cout << str << endl;


    string str2;
    str2.assign(str);
    cout << str2 << endl;

    //string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

    str2.assign(str, 0, 2);
    cout << str2 << endl;

}

/*
3.1.2.3 string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/

void test03()
{
    string str = "hello world";

    //for (int i = 0; i < str.size();i++)
    //{
    //	//cout << str[i] << endl;
    //	cout << str.at(i) << endl;
    //}

    //[]和at区别，[]访问越界 直接挂掉 ， at访问越界  抛出out_of_range异常

    try
    {
        //cout << str[100] << endl;
        cout << str.at(100) << endl;
    }
    catch (out_of_range & e)
    {
        cout << e.what() << endl;
    }
    catch (...)
    {
        cout << "异常捕获" << endl;
    }

}


/*
3.1.2.4 string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/

void test04()
{
    //
    //string str1 = "我";
    //string str2 = "爱北京";

    //str1 += str2;
    //cout << str1 << endl;

    //str1.append("天安门");
    //cout << str1 << endl;

    //查找
    string str = "abcdefgde";

    int pos =  str.find("de");
    //rfind 是从右往左查找
    if (pos == -1)
    {
        cout << "未找到字符串" << endl;
    }
    else
    {
        cout << "找到了字符串，位置为： " << pos << endl;
    }

    //替换
    //string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
    str.replace(1, 3, "11111");
    //a11111efgde
    cout << str << endl;
}


/*
3.1.2.6 string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。

int compare(const string &s) const;//与字符串s比较
int compare(const char *s) const;//与字符串s比较
3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

*/

void test05()
{
    string str1 = "abcde";
    string str2 = "abcdef";

    if (str1.compare(str2) == 0)
    {
        cout << "str1 == str2" << endl;
    }
    else if (str1.compare(str2) > 0)
    {
        cout << "str1 > str2" << endl;
    }
    else
    {
        cout << "str1 < str2" << endl;
    }
}

void test06()
{
    //子串
    //string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

    //string str = "abcdef";

    //   string subStr =	str.substr(0, 3);

    //cout << subStr << endl;


    string email = "zhangtao@sina.com";

    int pos = email.find("@"); // 8

    string userName = email.substr(0, pos);

    cout << userName << endl;

}

//解析字符串
void test07()
{
    string str = "www.itcast.com.cn";

    vector<string> v; //将 www  itcast  com  cn 单词截取到 vector容器中

    int start = 0;
    int pos = -1;

    while (true)
    {
        //www.itcast.com.cn
        pos = str.find(".", start);

        if (pos == -1)
        {
            //将cn截取出来
            string tempStr = str.substr(start,str.size() - start);
            v.push_back(tempStr);
            break;
        }

        string tempStr = str.substr(start, pos - start);

        v.push_back(tempStr);

        start = pos + 1;
    }

    for (vector<string>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << endl;
    }

}
/*
3.1.2.8 string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/
void test08()
{

    string str = "hello";

    str.insert(1, "111");

    //h111ello
    cout << str << endl;

    //删除
    str.erase(1, 3);

    cout << str << endl;
}

void doWork(string str)
{

}

void doWork2(const char* str)
{

}

//3.1.2.9 string和c-style字符串转换
void test09()
{
    const char * str = "abcd";

    //const char * 转为 string
    string s(str);

    //string 转为 const char *
    const char * str2 = s.c_str();

    //const char * 可以隐式类型转换为  string
    doWork(str2);
    //string 不可以隐式类型转换为  const char*
    //doWork2(s);
}


void test10()
{
    string s = "abcdefg";
    char& a = s[2];   //两个引用！
    char& b = s[3];

    a = '1';
    b = '2';

    cout << s << endl;
    cout << (int*)s.c_str() << endl;  //到这里是正常的！

    s = "pppppppppppppppppppppppp";   //这里重新分配了内存

    //a = '1';  //但是这里这样做相当于还对原来的内存地址做操作！  所以这里就报错了！
    //b = '2';

    cout << s << endl;
    cout << (int*)s.c_str() << endl;  //重新打印地址， 也可以发现地址已经变化了！
}

/*
写一个函数，函数内部将string字符串中的所有小写字母都变为大写字母。
*/
void test11()
{
    string str = "abcdEFg";

    for (int i = 0; i < str.size();i++)
    {
        //str[i] = toupper(str[i]);

        str[i] = tolower(str[i]);

    }

    cout << str << endl;
}


int main(){

    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    //test10();
    test11();

    return EXIT_SUCCESS;
}