#include <bits/stdc++.h>
using namespace std;

long double add() {
    return 0;
}

template<typename T, typename ... Args>
T add(T first, Args ... args) {
    return first + add(args ...);
}


int main()
{
    cout << add(1,3.5,1);
}
