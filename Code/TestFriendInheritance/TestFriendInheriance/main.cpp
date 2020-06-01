#include <iostream>
using namespace std;

class B;

class A {
    int secret;

public:
    A() {}
    A(int x) {secret = x;}
    friend class B;
};

class B {
public:
    B() {}

    int getSecret(A a) {return a.secret;}
};

class C : public B{
public:
    int getSecretByAskingDad(A a) {
        return B::getSecret(a);
    }
};

int main()
{
    A a(5);
    B b;
    C c;
    cout << c.getSecretByAskingDad(a);
    return 0;
}
