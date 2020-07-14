/*-----------------------------------------------------------------
    
    
    
    调整定容栈数组大小
    可以借鉴动态调整数组的经验


*/
#include<iostream>
#include<string>
using namespace std;

//实现一个移动数组的函数，将旧数组移动到新数组
string *s;//需要处理的旧数组
int N;//原数组大小
void resize(int max)
{
    string *temp = new string[max];
    for(int i = 0;i<N;i++)
    {
        temp[i]=s[i];
    }

    s = temp;//这部分存疑，C++如果回收内存之后，s指向的内存空间是否仍然有效？
    delete temp;
}

//实验，new 与 delete 之后的数组变化情况

int main()
{
    int *a = new int[10];
    int *temp = new int[20];
    for(int i = 0; i<20;i++)
    {
        a[i]=i;
        temp[i] = a[i];
    }

    a = temp;
    delete temp;
    for(int i = 0; i<10;i++)
        cout<<a[1];
}

//经过实验，delete 后的a和temp指向的内存空间被回收，所以这样写会造成内存泄漏错误
//故直接交换指针来改变内存大小在C++中是不可行的。java中貌似可以