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
            if (a[i] < 0)
            {
                a[i] += BASE;
                --a[i + 1];
            }
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

BigN operator - (const BigN &A, const BigN &B)
{
    BigN R; int k = max(A.n, B.n);
    R.resize(k);
    for (int i = 0; i < k; ++i) R[i] = A[i] - B[i];
    R.normalize();
    return R;
}

ostream &operator << (ostream &cout, const BigN &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}

int n, k;
BigN f[10001], Pow2[10001];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    FOR(i, 0, k) f[i] = 0;
    f[k] = 1;
    Pow2[0] = 1;
    REP(i, 1, n) Pow2[i] = Pow2[i - 1] + Pow2[i - 1];
    for (int i = k + 1; i <= n; ++i)
    {
        f[i] = f[i - 1] + f[i - 1] + Pow2[i - k - 1];
        f[i] = f[i] - f[i - k - 1];
    }
    cout << f[n];
}
