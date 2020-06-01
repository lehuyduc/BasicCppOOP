#include <iostream>

template <class T>
T sum (T* x, int size)
{
    T sum = 0;
    for(int i=0;i<size;i++)
        sum+=x[i];
    return sum;
}

int main()
{
    int T1[10]={0,1,2,3,4,5,6,7,8,9};
    int sumInt = sum(T1,10);
    std::cout << "sum: "<< sumInt << std::endl;
    
    float T2[10]={0.111,1.111,2.1,3.1,4.1,5.1,6.1,7.1,8.1,9.1};
    float sumFloat = sum(T2,10);
    std::cout << "sum: "<< sumFloat << std::endl;
}

