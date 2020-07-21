#include<iostream>

using namespace std;

//删除链表的尾节点
//遍历法
//创建链表
struct node
{
    int a;
    node* next;
};

//创建一个大小为20的链表
node* creat(int Array[])
{
    node *pre, *p ,*first;
    first = new node;
    first->next = NULL;
    pre = first;
    for(int i = 0; i < 20; i++)
    {
        p = new node;
        p->a=Array[i];
        p->next = NULL;//新节点的指针设为NULL.作为保险措施
        pre->next=p;
        pre = p;
    }
    return first;
}

void del(node* first)
{
    node *p,*temp;
    for(p = first;p->next!=NULL;p = p->next)
    {
        temp = p;//temp储存p变化前的节点，即当p节点为尾节点，temp为上一个节点
    }
    delete p;
    temp->next = NULL;
}
