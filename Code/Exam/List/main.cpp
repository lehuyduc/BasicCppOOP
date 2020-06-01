#include <iostream>
#include "List.hpp"
#include <stdio.h>
#include <string.h>
using std::cout;

typedef long long ll;

void testList()
{
    List<int> myList;

    myList.add(5);
    myList.add(6);
    myList.add(7);
    myList.printer();

    List<int>::Iterator it(myList);
    for (it.begin();!it.ended();it.next()) cout << (*it.get()) << " ";
    cout << "\n\n";

    List<double> dl;
    dl.add(5);
    dl.add(3.5);
    dl.add(-1);
    dl.printer();


    cout << "\n\n------------------------\n\n";
}

int main()
{
    testList();
}
