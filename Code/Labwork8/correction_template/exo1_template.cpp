#include <iostream>

template <class T>
T square (T& x)
{
    return x*x;
}

int main()
{
    int a = 2;
    int res = square(a);
    std::cout << res << std::endl;
    float b = 3.0;
    float res2 = square(b);
    std::cout << res2 << std::endl;
}
