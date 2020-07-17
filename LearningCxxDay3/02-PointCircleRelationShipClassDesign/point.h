#pragma  once
#include<iostream>
using namespace std;

//点类
class Point
{
public:

    //设置 x 、y
    void setX(int x);

    void setY(int y);

    //获取 x 、y
    int getX();

    int getY();

private:
    int m_X;
    int m_Y;
};

