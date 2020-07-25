/*
    采用链表实现下压堆栈。
    1.push()添加元素在表头插入结点
    2.pop()弹出元素删除表头结点
    3.size()方法通过计数N来统计
    4.isempty()判断N是否为0或者first是否为null
*/

struct node
{
    int a;
    node *next;
};

class Stack
{
private:
    node *first;
    int N;
public:
    Stack(/* args */);
    ~Stack();
    bool isempty(){return (first == nullptr||N == 0);}
    int size() {return N;}
    void push(int x)
    {
        node* pre = first;
        node *first = new node;//多次new同一个对象是否可行，理论上是可行的
        first->a = x;
        first->next = pre;
        N++;
        
    }
    int pop()
    {
        int r = first->a;
        node *temp = first->next;
        delete first;
        first = temp;
        return r;
    }

};

Stack::Stack(/* args */)
{
}

Stack::~Stack()
{
    delete first;
}
