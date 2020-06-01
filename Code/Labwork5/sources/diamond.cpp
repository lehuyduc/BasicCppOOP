#include <bits/stdc++.h>
using namespace std;

class Animal {
    double mass;
    Animal();
public:
    Animal(double m) {mass = m;}
    virtual void sound();
    virtual void sound(int);
};

class Dog : public virtual Animal {
    double dogGene;
public:
    Dog(double m, double dgene=0) : Animal(m), dogGene(dgene) {}
    void sound() {cout << "I am a dog\n";}
};

class Cat : public virtual Animal {
    double catGene;
public:
    Cat(double m, double cgene=0) : Animal(m), catGene(cgene) {}
    void sound(int n) {cout << "I am a cat\n";}
};

class DogCat : public Dog, public Cat {
    double DogCatLength;
public:
    DogCat(double m, double dgene, double cgene, double dclength) : Animal(m), Dog(dgene), Cat(cgene), DogCatLength(dclength) {}
};

int main()
{
    DogCat* a = new DogCat(0,1,2,3);
    a->sound(5);
    return 0;
}
