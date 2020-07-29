/*
    采用链表实现下压堆栈。
    1.push()添加元素在表头插入结点
    2.pop()弹出元素删除表头结点
    3.size()方法通过计数N来统计
    4.isempty()判断N是否为0或者first是否为null

    设计目标：
    1.可以处理任意类型的数据(c++中需使用模板，这里用任意类型代替，需要什么类型结点
    生成相应结点)，
    2.所需空间总是和集合大小成正比
    3.操作所需时间总是和集合大小无关
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
    first = nullptr;
    N = 0;
}

Stack::~Stack()
{
    delete first;
}
