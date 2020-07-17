#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"

/*
设计一个圆形类（AdvCircle），和一个点类（Point），计算点和圆的关系。
假如圆心坐标为x0, y0, 半径为r，点的坐标为x1, y1：
*/

////点类
//class Point
//{
//public:
//
//	//设置 x 、y
//	void setX(int x)
//	{
//		m_X = x;
//	}
//	void setY(int y)
//	{
//		m_Y = y;
//	}
//	//获取 x 、y
//	int getX()
//	{
//		return m_X;
//	}
//	int getY()
//	{
//		return m_Y;
//	}
//private:
//	int m_X;
//	int m_Y;
//};

//
////圆类
//class Circle
//{
//public:
//	//设置半径
//	void setR(int r)
//	{
//		m_R = r;
//	}
//	//获取半径
//	int getR()
//	{
//		return m_R;
//	}
//
//	//设置圆心
//	void setCenter(Point p)
//	{
//		m_Center = p;
//	}
//
//	//获取圆心
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//	//判断点和圆关系
//	void isInCircleByClass(Point p)
//	{
//
//		int distance = (m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY()) *(m_Center.getY() - p.getY());
//
//		int rDistance = m_R * m_R;
//
//		if (distance == rDistance)
//		{
//			cout << "成员函数判断：点在圆上" << endl;
//		}
//		else if (distance > rDistance)
//		{
//			cout << "成员函数判断：点在圆外" << endl;
//		}
//		else
//		{
//			cout << "成员函数判断：点在圆内" << endl;
//		}
//	}
//
//private:
//
//	int m_R; //半径
//
//	Point m_Center; // 圆心
//};

//利用全局函数 判断点和圆关系
void isInCircle( Circle c , Point p )
{

    int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) *(c.getCenter().getY() - p.getY());

    int rDistance = c.getR() * c.getR();

    if (distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > rDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }

}

void test01()
{
    Point p;
    p.setX(10);
    p.setY(9);

    Circle c;
    Point pCenter;
    pCenter.setX(10);
    pCenter.setY(0);
    c.setCenter(pCenter);
    c.setR(10);

    isInCircle(c, p);

    c.isInCircleByClass(p);
}

class A
{
    virtual void func() = 0;
};
class B :public A
{

};
class C :public B
{
};

int main(){
    test01();

    return EXIT_SUCCESS;
}