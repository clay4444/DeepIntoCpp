#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>
#include <ctime>
/*
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有: 姓名 年龄 电话 工资等组成
//通过Multimap进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息
*/

enum{ CAIWU,RENLI,YANFA};  //枚举类型  其实本质就是 0  1  2

class Worker
{
public:
    string m_Name;
    int m_Money;
};

void createWorker(vector<Worker>&v)
{
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5;i++)
    {
        Worker worker;
        worker.m_Name = "员工";
        worker.m_Name += nameSeed[i];

        worker.m_Money = rand() % 10000 + 10000; // 10000 ~ 19999

        v.push_back(worker);
    }
}


void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
    {
        //随机产生部门编号   0  1  2
        int dId = rand() % 3;
        m.insert(make_pair(dId, *it));
    }
}

void showWorker(multimap<int,Worker>&m)
{
    cout << "财务部门员工信息如下：" << endl;

    //  0  A  0  B  1 C   2 D  2 E

    multimap<int,Worker>::iterator pos = m.find(CAIWU);

    int num = m.count(CAIWU);
    int index = 0;
    for (; pos != m.end(), index<num; pos++,index++)
    {
        cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }


    cout << "人力部门员工信息如下：" << endl;
    pos = m.find(RENLI);

    num = m.count(RENLI);
    index = 0;
    for (; pos != m.end(), index < num; pos++, index++)
    {
        cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }


    cout << "研发部门员工信息如下：" << endl;
    pos = m.find(YANFA);

    num = m.count(YANFA);
    index = 0;
    for (; pos != m.end(), index < num; pos++, index++)
    {
        cout << "姓名： " << pos->second.m_Name << " 工资： " << pos->second.m_Money << endl;
    }


}

int main(){

    //随机数种子
    srand((unsigned int)time(NULL));

    vector<Worker>v;
    //1、创建5名员工
    createWorker(v);

    //2、员工分组
    multimap<int, Worker> m;
    setGroup(v, m);

    //3、分部门显示员工
    showWorker(m);


    //测试
    //for (vector<Worker>::iterator it = v.begin(); it != v.end();it++)
    //{
    //	cout << "姓名： " << it->m_Name << " 工资： " << it->m_Money << endl;
    //}

    return EXIT_SUCCESS;
}