#include <iostream>
#include "hashtable.hpp"
using namespace std;

int main()
{
    HashTable ht(1000);

    ht.add(5, 10);
    ht.add(11, 20);

    try {
        cout << ht.get(10) << "\n";
    }
    catch (string e) {cout << e << "\n";}
    cout << ht.get(11) << "\n";

    ht.add(12, 30);
    ht.remove(11);
    try {
        cout << ht.get(11);
    } catch(string e) {cout << e << "\n";}

    HashTable::Iterator it = ht.getIterator();
    for (it.begin(); !it.ended(); it.next()) cout << it.get() << " ";
    return 0;
}
