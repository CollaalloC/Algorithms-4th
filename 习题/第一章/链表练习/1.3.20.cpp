/*
    题目： 编写一个方法delete()，接受一个Int参数k，删除链表的第k个元素(如果它存在的话)

    分析：1.判断是否存在结点
        2.删除结点
*/


struct node
{
    int a;
    node* next;
};

node *p,*first;//存在一个链表
void del(int k)
{
    p = first;
    node *temp,*pre;
    pre = p;
    for(int i = 1; i<= k; i++)
    {
        if(p->next!= nullptr)//判断k结点是否存在。遍历
        {
            temp = pre;
            pre = p;
            p = p->next;
            //p结点为中间结点
            if(i == k)//遍历到k结点时,temp为前一结点，pre为p结点,p为下一个结点
            {
                delete pre;
                temp->next = p;
                return ;
            }
        }
        else
        {
            if(i == k)//k结点为尾节点时
            {
                delete p;
                pre->next = nullptr;
            }


            //k结点不存在时

            return ;//终止函数
        }
    }
}
