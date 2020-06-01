#include <iostream>
#include "queue.hpp"
using std::cout;
using std::string;

void testQueueInt()
{
    int a[] = {0,5,10,15,20,25};
    Queue<int,4> q;
    try {
        cout << q.pop() << " ";
    }
    catch (string e) {
        cout << e << "\n";
    }

    for (int i=0;i<=5;i++)
    try {
        q.push(a[i]);
    }
    catch (string e){
        cout << "Error at " << i << " " << e << "\n";
    }

    while (!q.isEmpty()) cout << q.pop() << " A\n";
}

void testQueueDouble()
{
    double a[] = {0.5,5.5,10.5,15.5,20.5,25.5};
    Queue<double,4> q;
    try {
        cout << q.pop() << " ";
    }
    catch (string e) {
        cout << e << "\n";
    }

    for (int i=0;i<=5;i++)
    try {
        q.push(a[i]);
    }
    catch (string e){
        cout << "Error at " << i << " " << e << "\n";
    }

    while (!q.isEmpty()) cout << q.pop() << " A\n";
}

void testIterator()
{
    double a[] = {0.5,5.5,10.5,15.5,20.5,25.5};
    Queue<double,4> q;
    try {
        cout << q.pop() << " ";
    }
    catch (string e) {
        cout << e << "\n";
    }

    for (int i=0;i<=5;i++)
    try {
        q.push(a[i]);
    }
    catch (string e){
        cout << "Error at " << i << " " << e << "\n";
    }

    Queue<double,4>::Iterator it = q.getIterator();
    for (it.begin();!it.ended();it.next()) cout << it.get() << " C\n";
}

int main()
{
   // testQueueInt();
    //testQueueDouble();
    testIterator();
    return 0;
}
