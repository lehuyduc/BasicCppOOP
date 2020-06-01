#pragma once
#include <iostream>
#include <cstdlib>
using std::cout;


class Stack {
private:
    void *m_v;
    unsigned m_dataSize;
    unsigned m_arraySize;
    int m_head;

protected:
    void copy(const Stack& st) {
        m_dataSize = st.m_dataSize;
        m_arraySize = st.m_arraySize;
        m_head = st.m_head;
        m_v = malloc(m_dataSize * m_arraySize);
        memcpy(m_v, st.m_v, m_dataSize*(m_head+1));  // values after stack top is garbage
    }

public:
    Stack() {m_v = nullptr; m_head = -1; m_dataSize = 0; m_arraySize = 0;}

    Stack(unsigned dataSize) {m_dataSize = dataSize; m_arraySize = 0; m_head = -1; m_v = nullptr;}
    Stack(const Stack& st) {
        copy(st);
    }

    ~Stack() {
        free(m_v);
    }

    Stack& operator=(const Stack& st) {
        if (this!=&st) {
            free(m_v);
            copy(st);
        }
        return (*this);
    }

    bool empty() const {
        return m_head==-1;
    }

    void push(const void *content) {
        if (m_head==m_arraySize-1) {
            m_v = realloc(m_v, m_dataSize*(m_arraySize+1));
            m_arraySize++;
        }
        m_head++;
        char* bytes = (char*)m_v;
        int from = m_head * m_dataSize;
        memcpy(bytes+from, content, m_dataSize);
    }

    void* head() const {
        void* res = malloc(m_dataSize);
        int from = m_head * m_dataSize;
        char* bytes = (char*)m_v;
        memcpy(res,bytes+from, m_dataSize);
        return res;
    }



    void* pop() {
        void* res = malloc(m_dataSize);
        int from = m_head * m_dataSize;
        char* bytes = (char*)m_v;
        memcpy(res,bytes+from, m_dataSize);
        m_head--;
        return res;
    }

    Stack& operator<<(const void* content) {
        push(content);
        return (*this);
    }
    Stack& operator>>(void* &content) {
        content = pop();
        return (*this);
    }
};

