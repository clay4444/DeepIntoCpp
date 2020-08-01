#include<iostream>
using namespace std;
#include <map>

/**
 * key-value
 * 不可以通过迭代器改变键值，所以是const iterator
 * multimap和map类似，唯一区别是multimap的键值可重复
 * map和multimap的底层数据结构都是红黑树！
 */



/*
3.8.2.1 map构造函数
map<T1, T2> mapTT;//map默认构造函数:
map(const map &mp);//拷贝构造函数
3.8.2.2 map赋值操作
map& operator=(const map &mp);//重载等号操作符
swap(mp);//交换两个集合容器

3.8.2.3 map大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空
3.8.2.4 map插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";
*/

void test01()
{
    map<int, int> m;

    //第一种插入方式
    m.insert(pair<int, int>(1,10));

    //第二种插入方式  推荐
    m.insert(make_pair(2, 20));

    //第三种插入方式
    m.insert(map<int, int>::value_type(3, 30));

    //第四种  这种和java类似！
    m[4] = 40;

    //cout << m[10] << endl; //如果利用第四种 使用未指定的key，生成一个key为为指定的值，value为0的数据插入到容器中

    for (map<int, int>::iterator it = m.begin(); it != m.end();it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }

}

/*
3.8.2.5 map删除操作
clear();//删除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg,end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(keyElem);//删除容器中key为keyElem的对组。
*/
void test02()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    m.erase(3); //删除传入key值

    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }

}

/*
3.8.2.6 map查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
*/

void test03()
{
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    map<int,int>::iterator ret = m.find(3);
    if (ret != m.end())
    {
        cout << "找到了 key为 " << ret->first << " value = " << ret->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    //统计  count
    int num =  m.count(4);
    cout << "key为4的对组个数为： " << num << endl;

    //lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
    map<int,int>::iterator pos = m.lower_bound(3);

    if (pos != m.end())
    {
        cout << "找到了lower_bound key: " << pos->first << " value: " << pos->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    //upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
    pos = m.upper_bound(3);
    if (pos != m.end())
    {
        cout << "找到了upper_bound key: " << pos->first << " value: " << pos->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }


    //equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<map<int, int>::iterator, map<int, int>::iterator>  ret2 = m.equal_range(3);

    if ( ret2.first != m.end() )
    {
        cout << "找到了equal_range中的 lower_bound的 key =  " << ret2.first->first << " value = " << ret2.first->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

    if (ret2.second != m.end())
    {
        cout << "找到了equal_range中的 upper_bound的 key =  " << ret2.second->first << " value = " << ret2.second->second << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }

}


class myCompareInt
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
void test04()
{
    map<int, int, myCompareInt> m;

    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;

    for (map<int, int, myCompareInt>::iterator it = m.begin(); it != m.end();it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
}

int main(){
    //test01();
    //test02();
    //test03();
    test04();

    return EXIT_SUCCESS;
}