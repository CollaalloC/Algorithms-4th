/* 
    题目：编写一个方法removeAfter()，接受一个链表结点作为参数并删除该结点的后续结点
    (如果参数结点或参数结点的后续为空则什么也不做)

    分析：
    1.删除后续结点需要逐个删除释放内存
    2.将参数结点作为尾节点，后续结点开始逐一删除
    3.在结点不为空的情况下
*/
struct node
{
    int a;
    node *next;
};


void removeAfter(node *del)
{
    node *temp;
    if (del != nullptr&&del->next != nullptr)
    {
        temp = del ->next;
        del ->next = nullptr;//参数结点设为尾节点
    }
    //删除后续结点
    for (node *i = temp; temp->next != nullptr; i = temp)
    {
        temp = i->next;
        delete i;
        //i作为删除结点，temp作为缓冲结点，逐结删除
    }
}