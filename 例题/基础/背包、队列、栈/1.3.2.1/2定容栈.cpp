#include <iostream>
#include <string>
#include <vector>

using namespace std;
//采用类模板或者函数模板实现泛型编程
class FixedCapacityStackOfStrings
{
private:
    int size;
    string *s;

public:
    FixedCapacityStackOfStrings(int n);
    ~FixedCapacityStackOfStrings();
    int get_size() { return size; }
    void push(string item) { s[size++] = item; }//压栈 但当数量超过容量时会越界，出现内存泄漏错误
    string pop() { return s[--size]; }//弹出
    bool isEmpty() { return get_size() == 0; }
};

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int n)
{
    size = 0;//统计压入栈的数量，并非栈的大小
    s = new string[n]; //确定数组的大小，确定容量；
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings()
{
    delete[] s; //回收内存，必须要有；
}
