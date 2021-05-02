#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
#include <bitset>
#include <unordered_map>

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array
#define ef else if
#define lb lower_bound

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 123;
const int BASE = 10000;
const int INF = 1e9 + 123;
struct matrix
{
    int m, n;
    LL a[68][68];

    matrix(const int &x, const int &y)
    {
        m = x; n = y;
        REP(i, 1, m) REP(j, 1, n) a[i][j] = 0;
    }

    void indetity(int x)
    {
        m = n = x;
        REP(i, 1, n) a[i][i] = 1;
    }

    LL *operator [] (int i) { return a[i]; }
    const LL *operator [] (int i) const { return a[i]; }

    void operator = (const matrix &A)
    {
        m = A.m; n = A.n;

        REP(i, 1, m) REP(j, 1, n)
            a[i][j] = A[i][j];
    }
} C(67, 67), res(1, 67);

matrix operator *(const matrix &A, const matrix &B)
{
    matrix C(A.m, B.n);
    REP(i, 1, C.m) REP(j, 1, C.n) REP(k, 1, A.n)
        (C[i][j] += A[i][k]*B[k][j])%=MOD;
    return C;
}

matrix operator ^(matrix &A, LL x)
{
    matrix C(A.n, A.n);
    C.indetity(A.n);

    while (x)
    {
        if (x&1) C = C*A;
        A = A*A;
        x >>= 1;
    }
    return C;
}

int g[15][15];
LL c[15][15];
void prepare()
{
    REP(i, 0, 5) c[i][0] = 1;
    REP(i, 1, 5) REP(j, 1, i) (c[i][j] += c[i - 1][j - 1] + c[i - 1][j])%=MOD;

    int x = 0;
    REP(j, 0, 10) REP(k, 0, 10 - j) g[j][k] = ++x;

    x = 0;

    REP(j, 0, 10) REP(k, 0, 10 - j)
    {
        ++x;
        if (j > 0)
            C[g[j - 1][k + 1]][x] = (LL)(j);
        if (k > 0)
        {
            C[g[j + 1][k - 1]][x] = (LL)(k);
            C[g[j][k - 1]][x] = (LL)(k);
        }
    }

    ++x;
    REP(j, 0, 10) REP(k, 0, 10 - j)
    {
        if (j > 0)
            C[g[j][k]][x] += (LL)(5)*c[5][j - 1]*c[4][k];
        C[g[j][k]][x] += (LL)(5)*c[5][j]*c[4][k];

        if (k > 0)
            C[g[j][k]][x] += (LL)(4)*c[4][j]*c[5][k - 1];
    }
    C[x][x] = 1;

    res[1][g[0][1]] = 1;
    res[1][x] = 5;
}

// MxN NxN
//C[i][j] = A[i][k]*B[k][j]

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);

    prepare();
    LL n;

    while (cin >> n)
    {
        --n;
        matrix A(0, 0), B(0, 0);
        A = C; B = res;
        A = A^n;
        B = B*A;
        cout << B[1][67] << endl;
    }
}
