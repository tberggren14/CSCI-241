#ifndef MYSTACK_H
#define MYSTACK_H
#include <iostream>

class mystack
{
    private:

    size_t stk_size = 0;
    size_t stk_capacity = 0;
    char* stack_array = nullptr;

    public:

    mystack() = default;
    mystack(const mystack&);
    ~mystack();
    mystack& operator=(const mystack&);
    size_t capacity() const;
    size_t size() const;
    bool empty() const;
    void clear();
    void reserve(size_t );
    const char& top() const;
    void push(char);
    void pop();
};
#endif
