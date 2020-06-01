#pragma once
#include <iostream>
using std::cout;

template<class T>
class StackTemplate {
    struct Element {
        T data;
        Element* next;
        Element() {}
        Element(T newData, Element* nextEle) : data(newData), next(nextEle) {}
        Element(const Element& ele) {data = ele.data; next = ele.next;}
    };

    Element* top;

    void copy(StackTemplate& st) {
        Element *it, *tmp, *nextTmp;
        it = st.top;
        if (it==nullptr) {top = nullptr; return;}

        top = new Element(*it);
        tmp = top;
        while (it != nullptr) {
            it = it->next;
            if (it!=nullptr) {
                nextTmp = new Element(*it);
                tmp->next = nextTmp;
                tmp = nextTmp;
            }
        }
    }

public:
    StackTemplate() {top = nullptr;}
    StackTemplate(StackTemplate& st) {copy(st);}

    void push(T newdata) {
        Element *newtop = new Element(newdata, top);
        top = newtop;
    }

    T head() const {
        return top->data;
    }

    T pop() {
        T res = top->data;
        Element* tmp = top;
        top = top->next;
        delete tmp;
        return res;
    }

    bool empty() {
        return top==nullptr;
    }

    StackTemplate& operator=(StackTemplate& st) {
        if (this!=&st) {
            while (!empty()) pop();
            copy(st);
        }
        return (*this);
    }
};
