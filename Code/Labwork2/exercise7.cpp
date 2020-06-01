#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <string>
using std::string;
using std::to_string;
using std::cout;

double sqr(double x) {return x*x;}
double norm(double x, double y) {return sqrt(sqr(x) + sqr(y));}

struct Complex {
    double x,y;
    double r,theta;

    void polarize() {
        r = norm(x,y);
        theta = atan2(y,x);
    }

    Complex() {x = y = r = theta = 0;}
    Complex(double a, double b) {
        x = a;
        y = b;
        polarize();
    }

    std::string disp() {
        return ("" + to_string(x) + " + " + to_string(y) + "i");
    }

    void print() {
        std::cout << x << " + " << y << "i";
    }
};

inline Complex add(Complex a, Complex b) {
    return Complex(a.x + b.x, a.y + b.y);
}

inline Complex sub(Complex a, Complex b) {
    return Complex(a.x - b.x, a.y - b.y);
}

inline Complex mul(Complex a, Complex b) {
    return Complex(a.x*b.x - a.y*b.y, a.x*b.y + a.y*b.x);
}

inline Complex divi(Complex a, Complex b) {
    Complex conjugate = Complex(b.x, -b.y);
    return mul(a,conjugate);
}


void test(Complex a, Complex b, int op) {
    if (op==1)
        cout << "(" << a.disp() << ") + " << "(" << b.disp() << ") = " << add(a,b).disp() << "\n";

    if (op==2)
        cout << "(" << a.disp() << ") - " << "(" << b.disp() << ") = " << sub(a,b).disp() << "\n";

    if (op==3)
        cout << "(" << a.disp() << ") * " << "(" << b.disp() << ") = " << mul(a,b).disp() << "\n";

    if (op==4)
        cout << "(" << a.disp() << ") / " << "(" << b.disp() << ") = " << divi(a,b).disp() << "\n";

}


int main()
{
    Complex a[100],b[100];

    a[0] = Complex(1,5);
    b[0] = Complex(-3,-1);

    a[1] = Complex(-4,4);
    b[1] = Complex(3,2);

    a[2] = Complex(2,5);
    b[2] = Complex(5,-3);

    a[3] = Complex(3,-3);
    b[3] = Complex(-2,2);

    int n = 4;
    for (int i=0;i<n;i++) {
        for (int j=1;j<=4;j++) test(a[0],b[0],j);
        cout << "\n\n######################\n\n";
    }

}
