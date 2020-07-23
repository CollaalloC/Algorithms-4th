/* 

    题目：编写一个方法find()，接受一条链表和一个字符串key作为参数。如果链表中的某个结点
    item的值为key，则方法返回true，否则返回false

    分析：
    1.遍历查找
    2.存在性查找，多个结点符合条件不用判断
*/
#include<string>
using namespace std;

struct node
{
    string s;
    node *next;
};

bool find(node* first, string key)
{
    node *temp;
    for(node *i = first; i->next!=nullptr; i = i->next)
    {
        if(i->s == key)
        {
            return true;
        }
        else if(i->next == nullptr && i ->s != key)
        {
            return false;
        }
    }

}