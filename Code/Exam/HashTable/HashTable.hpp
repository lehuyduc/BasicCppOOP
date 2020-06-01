#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
using std::cout;

typedef long long ll;

class HashTable {
    int* values;
    bool* isValues;
    unsigned size;

    HashTable() {}

public:

    unsigned hf(int key) {
        return (ll(key)*13 + 17) % ll(1000000007);
    }
private:
    void cleanup() {
        delete[] values;
        delete[] isValues;
    }

    void copy(const HashTable& ht) {
        size = ht.size;
        values = new int[size];
        memcpy(values, ht.values, sizeof(int)*size);
        isValues = new bool[size];
        memcpy(isValues, ht.isValues, sizeof(bool)*size);
    }

public:
    HashTable(int N) {
        size = N;
        values = new int[N];
        isValues = new bool[N];
        for (int i=0;i<N;i++) isValues[i] = false;
    }

    HashTable(const HashTable& ht) {
        copy(ht);
    }

    ~HashTable() {
        cleanup();
    }

    HashTable& operator=(const HashTable& ht) {
        if (this!=&ht) {
            cleanup();
            copy(ht);
        }
        return (*this);
    }

    void add(int key,int value) {
        unsigned hash = hf(key) % size;
        values[hash] = value;
        isValues[hash] = true;
    }

    void remove(int key) {
        unsigned hash = hf(key) % size;
        isValues[hash] = false;
    }

    bool exist(int key) {
        unsigned hash = hf(key) % size;
        return isValues[hash];
    }

    int get(int key) {
        unsigned hash = hf(key) % size;
        if (!isValues[hash])
            throw std::string("Invalid hash table get");
        return values[hash];
    }

    class Iterator {
        int pos;
        const HashTable* ht;

    public:
        Iterator(const HashTable& htt) {ht = &htt;}

        void begin() {pos = 0; while (!ht->isValues[pos]) pos++;}

        bool ended() const {return pos>=ht->size;}

        void next() {pos++; while (pos<ht->size && !ht->isValues[pos]) pos++;}

        int get() const {
            if (ended())
                throw std::string("Invalid iterator get");
            return ht->values[pos];
        }
    };

    Iterator getIterator() {return Iterator(*this);}
};
