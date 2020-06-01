#include <iostream>
using std::cout;

class A {
    int* conster;

    A() {}

public:
    A(int x) {conster = new int; *conster = x;}

    int* getter() const {return conster;}
};

int main()
{
    A a(5);
    return 0;
}
