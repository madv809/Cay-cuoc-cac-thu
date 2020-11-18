#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>

using namespace std;
const int BASE = 10000;
struct BigN
{
    int a[2304], n;

    void resize(int x) {n = x; for (int i = 0; i < n; ++i) a[i] = 0;}
    void trim() {while (n > 1 && a[n - 1] == 0) --n;}
    void normalize()
    {
        for (int i = 0; i < n - 1; ++i)
        {
            a[i + 1] += a[i]/BASE;
            a[i] %= BASE;
        }
        trim();
    }

    int &operator [] (int i) {return a[i];}
    const int operator [] (int i) const {return a[i];}

    void operator = (int x) {a[0] = x; n = 1;}
    void operator = (const BigN &A) {n = A.n; for (int i = 0; i < n; ++i) a[i] = A[i];}
    void operator -= (int x) {a[0] -= 1; normalize();}
    void operator += (int x) {a[0] += 1; normalize();}
};

BigN operator + (const BigN &A, const BigN &B)
{
    BigN R; int k = max(A.n, B.n);
    R.resize(k + 1);
    for (int i = 0; i < k; ++i) R[i] = A[i] + B[i];
    R.normalize();
    return R;
}

ostream &operator << (ostream &cout, const BigN &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}

int n;
BigN f[1001];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    f[0] = 0;
    f[1] = 0;
    f[2] = 1;
    f[3] = 1;
    f[4] = 3;
    f[5] = 5;
    REP(i, 6, 1000)
    {
        f[i] = f[i - 1] + f[i - 1];
        if (i&1) f[i] -= 1;
        else f[i] += 1;
    }
    while ((cin >> n)) cout << f[n] << endl;
}
