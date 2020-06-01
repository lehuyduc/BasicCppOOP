#include <iostream>
#include "GenericMaze.hpp"
#include "Random.hpp"
using std::cout;

template<class T>
class GenericRandomMaze : public GenericMaze<T> {
    int nwall, maxLength;

public:
    GenericRandomMaze(int nrow,int ncol, int walls, int maxLen) : GenericMaze<T>(nrow, ncol) {
        nwall = walls;
        maxLength = maxLen;
    }

    void generateWalls() override {
        static const int dx[4] = {1,0,0,-1}; // 4 directions
        static const int dy[4] = {0,1,-1,0};

        int dem = 0;
        while (dem < nwall) {
            int i = Random::rand()%(this->nrow), j = Random::rand()%(this->ncol);
            //cout << dem << " AA\n";
            if (GenericMaze<T>::isWalled(GenericPoint2D<T>(i,j))) continue; // if there's already a wall here
            int from = Random::rand()%4;
            int wallLength = Random::rand()%maxLength + 1; // pick a random wall length
            for (int it=from; it<from+4; it++) { // pick a random wall direction
                int k = it%4;
                int x = i + (wallLength-1)*dx[k], y = j + (wallLength-1)*dy[k];
                if (!GenericMaze<T>::inside(GenericPoint2D<T>(x,y))) continue;

                for (int t=0;t<wallLength;t++)
                    GenericMaze<T>::cells[i + t*dx[k]][j + t*dy[k]].setFlag(1); // assign the values
                dem += 1;
                break;
            }
        }
    }
};
