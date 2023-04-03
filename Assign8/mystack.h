#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

struct node
{
    int value;
    node* next;
    
    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};

class mystack
{
    private:

    size_t stack_size = 0;
    node* stack_top = nullptr;
    
    public:

    mystack() = default;
    mystack(const mystack&);
    ~mystack();
    mystack& operator=(const mystack&);
    size_t size() const;
    bool empty() const;
    void clear();
    const int& top() const;
    void push(int);
    void pop();
    void clone(const mystack&);
};
#endif