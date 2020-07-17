#include<iostream>
using namespace std;

/*
设计立方体类(Cube)，求出立方体的面积( 2*a*b + 2*a*c + 2*b*c )和体积( a * b * c)，
分别用全局函数和成员函数判断两个立方体是否相等。
*/

class Cube
{
public:
    //设置长宽高
    void setL(int l)
    {
        m_L = l;
    }
    void setW(int w)
    {
        m_W = w;
    }
    void setH(int h)
    {
        m_H = h;
    }
    //获取长宽高
    int getL()
    {
        return m_L;
    }
    int getW()
    {
        return m_W;
    }
    int getH()
    {
        return m_H;
    }

    //求面积
    int calculateS()
    {
        return 2 * m_L*m_W + 2 * m_W*m_H + 2 * m_L*m_H;
    }

    //求体积
    int calculateV()
    {
        return m_L * m_W * m_H;
    }

    //利用成员函数 判断立方体是否相等
    bool compareCubeByClass( Cube &c )
    {
        return m_L == c.getL() &&  m_W == c.getW() && m_H == c.getH();
    }


private:
    int m_L; //长
    int m_W; //宽
    int m_H; //高
};


//利用全局函数 判断两个立方体是否相等
bool compareCube( Cube &c1, Cube &c2 )
{
    /*if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())
    {
    return true;
    }
    return false;*/

    return c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH();
}

void test01()
{
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);

    cout << "c1面积为： " << c1.calculateS() << endl; //600
    cout << "c1体积为： " << c1.calculateV() << endl; //1000

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);

    //利用全局函数判断 c1 和 c2是否相等

    bool ret = compareCube(c1, c2);
    if (ret)
    {
        cout << "c1 与 c2 相等" << endl;
    }
    else
    {
        cout << "c1 与 c2 不相等" << endl;
    }

    //利用成员函数 判断  c1 和 c2是否相等
    ret = c1.compareCubeByClass(c2);
    if (ret)
    {
        cout << "成员函数判断：c1 与 c2 相等" << endl;
    }
    else
    {
        cout << "成员函数判断：c1 与 c2 不相等" << endl;
    }

}

int main(){
    test01();

    return EXIT_SUCCESS;
}