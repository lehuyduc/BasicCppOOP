#pragma once
#include <iostream>
#include "ListException.hpp"

template<class T>
class List {
    struct Element {
        T *data;
        Element *next;
        Element() {}
        Element(const Element& e) {data = e.data; next = e.next;}

        Element(const T& content, Element* nextEle) {
            data = new T(content);
            next = nextEle;
        }
    };

    Element *head, *last;

public:
    class ListIterator {
        Element *head, *current;
        ListIterator() {}
    public:
        ListIterator(const ListIterator& it) : head(it.head), current(it.current) {}
        ListIterator(const List& myList) : head(myList.head), current(myList.head) {}

        void begin() {
            current = head;
        }

        bool ended() {
            return current==nullptr;
        }

        void next() {
            if (current==nullptr)
                throw ListException("ListIterator::next() nullptr");
            current = current->next;
        }

        const T* getData() const {
            if (current==nullptr)
                throw ListException("ListIterator::get() nullptr");
            return current->data;
        }

        void setData(const T& content) {
            delete current->data;
            current->data = new T(content);
        }
    };

public:
    List() {head = nullptr; last = nullptr;}

    void add(const T& content) {
        Element *e = new Element(content, nullptr);
        if (head==nullptr) {
            head = e;
            last = e;
            return;
        }
        last->next = e;
        last = e;
    }

    ListIterator getIterator() {return new ListIterator(*this);}

    void printer() {
        ListIterator it(*this);
        for (it.begin();!it.ended();it.next()) cout << (*it.getData()) << " ";
    }
};
