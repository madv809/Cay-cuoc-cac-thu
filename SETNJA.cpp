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
#define ar array
 
using namespace std;
const LL MOD = 1e9+7;
const int BASE = 10000;
struct big
{
    int n;
    int a[2304];
 
    void resize (int x) {n = x; FOR(i, 0, n) a[i] = 0;}
    void trim () {while (n > 1 && a[n - 1] == 0) --n;}
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
 
    void operator = (const int &x)
    {
        n = 1;
        a[0] = x;
    }
    void operator = (const big &A)
    {
        n = A.n;
        for (int i = 0; i < n; ++i) a[i] = A[i];
    }
};
 
big operator + (const big &A, const big &B)
{
    big R;
    if (A.n >= B.n)
    {
        R = A; ++R.n; R[R.n - 1] = 0;
        for (int i = 0; i < B.n; ++i) R[i] += B[i];
    }
    else
    {
        R = B; ++R.n; R[R.n-1] = 0;
        for (int i = 0; i < A.n; ++i) R[i] += A[i];
    }
    R.normalize();
    return R;
}
 
big operator * (const big &A, const int &x)
{
    big R; R.resize(A.n + 1);
    for (int i = 0; i < A.n; ++i) R[i] = A[i]*x;
    R.normalize();
    return R;
}
 
ostream &operator << (ostream &cout, const big &A)
{
    printf("%d",A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}
 
big f[10001], g[10001];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    string s; getline(cin,s); s = '@'+s;
    f[0] = 1; g[0] = 1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == '*')
        {
            g[i] = g[i-1]*3;
            f[i] = f[i-1]*5 + g[i-1];
        }
        else if (s[i] == 'L')
        {
            g[i] = g[i-1];
            f[i] = f[i-1]*2;
        }
        else if (s[i] == 'R')
        {
            g[i] = g[i-1];                             // L *  R
            f[i] = f[i-1]*2 + g[i-1];                  // 2 12
        }                                              // 1 3
        else
        {
            f[i] = f[i-1];
            g[i] = g[i-1];
        }
    }
    cout << f[s.length()-1];
}
