#pragma once
#include <iostream>

class Randomize {
    static long long seed = -1;
    static long long base = (long long)1000000007; // prime number

public:
    void init(long long seeder) {seed = seeder;}

    int rand() {
        if (seed==-1) seed = 13;
        return (seed*113 + 17) % base;
    }
};
