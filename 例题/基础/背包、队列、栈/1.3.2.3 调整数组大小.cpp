/*-----------------------------------------------------------------
    
    
    
    调整定容栈数组大小
    可以借鉴动态调整数组的经验


*/
#include <iostream>
#include <string>
using namespace std;

//实现一个移动数组的函数，将旧数组移动到新数组
string *s; //需要处理的旧数组
int N;     //原数组大小
int S;     //原栈大小
void resize(int max)
{
    string *temp = new string[max];
    for (int i = 0; i < N; i++)
    {
        temp[i] = s[i];
    }
    /*
    s = temp;//这部分存疑，C++如果回收内存之后，s指向的内存空间是否仍然有效？
    delete temp;
    */
    //错误版本
    delete[] s; //删除原先指针指向的内存空间，将更改大小后的内存空间指向s,偷梁换柱
    s = temp;
    temp = NULL; //避免内存泄漏(是否有用存疑)
}

//实验，new 与 delete 之后的数组变化情况

int main()
{
    int *a = new int[10];
    int *temp = new int[20];
    for (int i = 0; i < 20; i++)
    {
        a[i] = i;
        temp[i] = a[i];
    }

    a = temp;
    delete temp;
    for (int i = 0; i < 10; i++)
        cout << a[1];
}

//经过实验，delete 后的a和temp指向的内存空间被回收，所以这样写会造成内存泄漏错误
//故直接交换指针来改变内存大小在C++中是不可行的。java中貌似可以
int size;
void push(string temp)
{
    //数组大小增长到栈的容量大小时，改变数组大小，增加一倍
    if (N == S)
        resize(2 * N);
    //继续添加元素
    s[N++] = temp; //添加后N容量增大。数组下标对应数组大小N-1,所以用N++
    //N为（N-1)+1,即元素添加到数组，然后数组数量N+1,为N++
}

string pop()
{
    //栈顶删除元素
    string temp = s[--N]; //这里不能用N--,数组大小N比下标多一位，所以先要N-1取出最新元素下标，
    s[N] = ' ';           //避免对象游离。(咋也不知道，日后补充)

    if (N > 0 && N == S / 4) //保证数组大小处于栈容量半满的地方。
        resize(S / 2);

    return temp;
}

//将数组大小控制在栈容量一半的程度，可以减少频繁调整数组大小带来的开支，提升效率