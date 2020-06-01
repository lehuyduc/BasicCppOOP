#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 6002;
int m, n, p;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], d[maxn][maxn];

void mult1()
{
    int i,j,k;
    for (i=1;i<=m;i++)
        for (j=1;j<=p;j++)
            for (k=1;k<=n;k++)
                c[i][j] += a[i][k]*b[k][j];
}

void mult2()
{
    int i,j,k;
    for (i=1;i<=m;i++)
        for (k=1;k<=n;k++)
            for (j=1;j<=p;j++)
                d[i][j] += a[i][k]*b[k][j];
}

int main()
{
    int i,j;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, ender;

    m = 1000; n = 998; p = 999;
    for (int i=1;i<=6000;i++)
        for (int j=1;j<=6000;j++)
    {
        a[i][j] = rand()%1000+1; b[i][j] = rand()%1000+1; c[i][j] = 0; d[i][j] = 0;
    }

    start = std::chrono::high_resolution_clock::now();
    mult1();
    ender = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(ender-start).count();
    cout << "mult1: " << elapsed_time << "\n";

    start = std::chrono::high_resolution_clock::now();
    mult2();
    ender = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(ender-start).count();
    cout << "mult2: " << elapsed_time << "\n";


    start = std::chrono::high_resolution_clock::now();
    mult2();
    ender = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(ender-start).count();
    cout << "mult2: " << elapsed_time << "\n";

    start = std::chrono::high_resolution_clock::now();
    mult1();
    ender = std::chrono::high_resolution_clock::now();
    elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(ender-start).count();
    cout << "mult1: " << elapsed_time << "\n";

    for (i=1;i<=m;i++)
        for (j=1;j<=p;j++) if (c[i][j]!=d[i][j]) cout << "false\n";

    cout << "success";
    return 0;
}
