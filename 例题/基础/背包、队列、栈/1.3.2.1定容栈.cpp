#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FixedCapacityStackOfStrings
{
private:
    int size;
    string *s;

public:
    FixedCapacityStackOfStrings(int n);
    ~FixedCapacityStackOfStrings();
    int get_size() { return size; }
    void push(string item) { s[size++] = item; }
    string pop() { return s[--size]; }
    bool isEmpty() { return get_size() == 0; }
};

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int n)
{
    size = 0;
    s = new string[n];
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings()
{
    delete[] s;
}
