#include "Random.hpp"

long long Random::seed = -1;
long long Random::base = (long long)1000000007;

void Random::init(long long seeder) {seed = seeder;}

int Random::rand() {
    if (seed==-1) seed = 13;
    if (seed%2==0) seed = (seed*113 + 17) % base;
    else seed = (seed * 131 + 23) % base;
    return seed%base;
}
