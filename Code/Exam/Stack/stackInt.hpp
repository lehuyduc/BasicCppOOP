#pragma once
#include "stack.hpp"
using std::cout;

class StackInt : private Stack
{
public:
    StackInt() : Stack(sizeof(int)) {}

    StackInt(StackInt& st) : Stack(st) {}


    void push(const int& content) {
        Stack::push((void*)&content);
    }

    bool empty() {
        return Stack::empty();
    }

    int head() const{
        void* res = Stack::head();
        return (*(int*)res);
    }

    int pop() {
        void* res = Stack::pop();
        return (*(int*)res);
    }

    StackInt& operator=(const StackInt& st) {
        Stack::operator=(st);
        return (*this);
    }

    StackInt& operator<<(int x) {
        push(x);
        return (*this);
    }
    StackInt& operator>>(int& x) {
        x = pop();
        return (*this);
    }
};

