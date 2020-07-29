/*
    采用链表实现队列
    1.first指向开始结点，last指向尾节点
    2.enqueue()入列元素添加到尾结点
    3.dequeue()出列元素从头节点删除
    4.size()和isempty()方法与算法1.2类似

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

class Queue
{
private:
    node *first;
    node *last;
    int N;
public:
    Queue(/* args */);
    ~Queue();
    int size() {return N;}
    bool isempty() {return N == 0;}
    void enqueue(int t) //表尾添加元素
    {
        node *oldlast = last;
        last = new node;
        last ->a = t;
        last ->next = nullptr;
        if(isempty())
            first = last;
        else
        {
            oldlast ->next = last;
        }
        N++;

    }

    int dequenue()//删除表头元素
    {
        node *temp;
        int tem;
        temp = first->next;
        tem = first->a;
        delete first;
        first = temp;
        if (isempty())//删除后进行判断，此时first = last
        {
            last = nullptr;//first = last = nullptr
            return ;
        }
        N--;
        return tem;
    }
};

Queue::Queue(/* args */)
{
    first = nullptr;
    last = nullptr;
    N = 0;
}

Queue::~Queue()
{
    delete first;
    delete last;
}
