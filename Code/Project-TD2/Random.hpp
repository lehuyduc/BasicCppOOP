#pragma once
#include <iostream>

class Random {
    static long long seed;
    static long long base; // prime number

public:
    static void init(long long seeder);

    static int rand();
};
