#pragma once
#include <iostream>
using std::cout;

template <class T>
class List {
    struct Element {
        T* data;
        Element* next;

        Element() {}
        Element(const T& content, Element* next_ele) {
            data = new T(content);
            next = next_ele;
        }
    };

    Element *head, *last;

public:
    class Iterator {
        Element *head, *current;
    public:

        Iterator() {head = nullptr; current = nullptr;}
        Iterator(const Iterator& it) {head = it.head; current = it.current;}

        Iterator(const List& list) {head = list.head; current = list.head;}

        void begin() {
            current = head;
        }

        bool ended() {
            return current==nullptr;
        }

        void next() {
            current = current->next;
        }

        const T* get() const {
            return current->data;
        }

        void set(const T& content) {
            delete current->data;
            current->data = new T(content);
        }
    };

    List() {head = nullptr; last = nullptr;}

    Iterator getIterator() {return Iterator(*this);}

    void add(const T& content) {
        Element *ele = new Element(content, nullptr);
        if (head==nullptr) {
            head = ele;
            last = ele;
            return;
        }
        last->next = ele;
        last = ele;
    }

    void printer() {
        Iterator it = getIterator();
        for (it.begin();!it.ended();it.next()) {
            cout << (*it.get()) << " ";
        }
    }
};
