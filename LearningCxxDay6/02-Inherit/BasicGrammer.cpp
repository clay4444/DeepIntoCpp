#include<iostream>
using namespace std;

/**
 * 01-基础语法
 */

//class News
//{
//public:
//
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//	void leftList()
//	{
//		cout << "公共的左侧列表" << endl;
//	}
//
//	void content()
//	{
//		cout << "新闻播报..." << endl;
//	}
//};
//
//
//class Sport
//{
//public:
//
//	void header()
//	{
//		cout << "公共的头部" << endl;
//	}
//	void footer()
//	{
//		cout << "公共的底部" << endl;
//	}
//	void leftList()
//	{
//		cout << "公共的左侧列表" << endl;
//	}
//
//	void content()
//	{
//		cout << "世界杯赛况..." << endl;
//	}
//};


//利用继承模拟网页
//继承优点： 减少重复的代码，提高代码复用性
class BasePage
{
public:
    void header()
    {
        cout << "公共的头部" << endl;
    }
    void footer()
    {
        cout << "公共的底部" << endl;
    }
    void leftList()
    {
        cout << "公共的左侧列表" << endl;
    }
};
// 语法： class 子类 ： 继承方式   父类
// News		子类    派生类
// BasePage 父类    基类
class News : public BasePage
{
public:
    void content()
    {
        cout << "新闻播报..." << endl;
    }
};

class Sport :public BasePage
{
public:
    void content()
    {
        cout << "世界杯..." << endl;
    }

};


void test01()
{
    News news;
    cout << "新闻页面内容如下：" << endl;
    news.header();
    news.footer();
    news.leftList();
    news.content();


    Sport sp;
    cout << "体育页面内容如下：" << endl;
    sp.header();
    sp.footer();
    sp.leftList();
    sp.content();

}


int main(){
    test01();

    return EXIT_SUCCESS;
}