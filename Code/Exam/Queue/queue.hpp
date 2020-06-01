#include <iostream>
#include <cstdio>
#include <cstdlib>
using std::cout;

template<class T, int capacity>
class Queue {
    T* data;
    int first, last, n;

    int getCapacity() const {
        return capacity;
    }

    int getFirst() const {
        return first;
    }

    int getLast() const {
        return last;
    }

    T getAt(int i) const {
        return data[i];
    }

    public:
    Queue() {
        if (capacity <= 0)
            throw std::string("Negative queue capacity");
        first = 0;
        last = -1;
        n = 0;
        data = new T[capacity];
    }

    bool isFull() {
        return n==capacity;
    }

    bool isEmpty() {
        return n==0;
    }

    void push(T content) {
        if (isFull())
            throw std::string("push full queue");
        last = (last+1)%capacity;
        data[last] = content;
        cout << last << " " << data[last] << " A\n";
        n++;
    }

    T head() const {
        return data[first];
    }

    T pop() {
        if (isEmpty())
            throw std::string("Pop empty queue");
        T res = data[first];
        first = (first+1)%capacity;
        n--;
        return res;
    }

    class Iterator {
        int pos, iterated;
        const Queue* const q;
        Iterator() {}
    public:
        Iterator(const Queue& newQ) : q(&newQ) {pos = newQ.first; iterated = 0;}

        void begin() {
            pos = q->getFirst();
            iterated = 0;
        }

        bool ended() const {
            return iterated==capacity;
        }

        void next() {
            pos = (pos+1)%capacity;
            iterated++;
        }

        const T get() const {
            return q->getAt(pos);
        }
    };

    Iterator getIterator() {return Iterator(*this);}
};
