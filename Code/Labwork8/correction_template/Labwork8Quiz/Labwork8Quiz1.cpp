#include <iostream>
#include <cmath>
using std::cout;

template<class T>
T square(T a) {return a*a;}

template<class T>
T summing(T a[], int n) {
    T res = 0;
    for (int i=0;i<n;i++) res = res + a[i];
    return res;
}

int main()
{
    int a = 5;
    double b = 10;
    cout << square(a) << " " << square(b) << " " << square(char(7)) << "\n";

    int ai[5] = {1,2,3,5,7};
    double ad[4] = {2.5, 3.5, 4, 1.2};

    cout << "sum integer array = " << summing(ai,5) << "\n";
    cout << "sum double array  = " << summing(ad,4) << "\n";
    return 0;
}


