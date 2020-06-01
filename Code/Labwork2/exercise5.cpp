#include <cstdlib> /// exit () declaration
#include <iostream>
using std::cout ; /// without including a l l std , we can declare
using std::cin;  // which parts are v i s i b l e without using ”std ::”

void overflow() {  // called when not enough memory
    cout << "Memory run out. Will try to get more\n";
    cout << "Get more failed. Exiting\n";
    exit(-1);
}

int main()
{
    long size;
    cout << "wished size: ";
    cin >> size;
    for (int nbloc=1; ;nbloc++) {
        int *adr = new(std::nothrow) int[size];
        if (adr==NULL) {
            cout << "Not enough memory\n";
            exit(-1);
        }
        cout << "Allocating block number " << nbloc << "\n";
    }
    return 0;
}
