
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
const LL MOD = 1e9+7; const LL INF = 1000000000000000001;
const int mxn = 2e6+5; const int BASE = 10;
struct BigN
{
    int n;
    int a[2900];

    void resize (int x) {for (int i = 0; i < x; ++i) a[i] = 0; n = x;}
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
    void operator = (int x)
    {
        a[0] = x;
        n = 1;
    }
    void operator = (const BigN &A)
    {
        n = A.n;
        for (int i = 0; i < n; ++i) a[i] = A[i];
    }
};
BigN A, f10[120], d10[120];

BigN operator + (const BigN &A, const BigN &B)
{
    BigN R;
    R = 0; int k = max(A.n, B.n);
    R.resize(k + 1);
    if (A.n > B.n)
    {
        for (int i = 0; i < A.n; ++i) R[i] = A[i];
        for (int i = 0; i < B.n; ++i) R[i] += B[i];
    }
    else
    {
        for (int i = 0; i < B.n; ++i) R[i] = B[i];
        for (int i = 0; i < A.n; ++i) R[i] += A[i];
    }
    R.normalize();
    return R;
}

BigN operator * (const BigN &A, const BigN &B)
{
    BigN R;
    R = 0;
    R.resize(A.n + B.n);
    for (int i = 0; i < A.n; ++i)
        for (int j = 0; j < B.n; ++j)
        {
            R[i + j] += A[i]*B[j];
            R[i + j + 1] += R[i + j]/BASE;
            R[i + j] %= BASE;
        }
    R.normalize();
    return R;
}

BigN operator * (const BigN &A, const int &x)
{
    BigN R; R.resize(A.n + 10);
    for (int i = 0; i < A.n; ++i) R[i] = A[i]*x;
    R.normalize();
    return R;
}

istream &operator >> (istream &cin, BigN &A)
{
    string s;
    cin >> s;
    int k = s.length(), x;
    A = 0; A.resize(k + 1);
    for (int i = 0; i < k; ++i)
    {
        x = (k - 1 - i);
        A[x] = A[x]*10 + (s[i] - '0');
    }
    A.normalize();
    return cin;
}

ostream &operator << (ostream &cout, const BigN &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%d", A[i]);
    return cout;
}

void solve ()
{
    BigN res; res = 0;
    for (int dig = 1; dig < 10; ++dig)
    {
        BigN tmp; tmp = 0;
        for (int i = A.n - 1; i >= 1; --i)
        {
            BigN r; r = 0; r = f10[i]*A[i];
            tmp = tmp + r;
            if (A[i] > dig) tmp = tmp + d10[i];
            else if (A[i] == dig)
            {
                BigN C; C.resize(i);
                for (int j = 0; j < i; ++j)
                    C[j] = A[j];
                ++C[0];
                tmp = tmp + C;
            }
        }
        if (A[0] >= dig) ++tmp[0];
        tmp = tmp*dig;
        res = res + tmp;
    }
    cout << res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> A;
    d10[0] = 1;
    for (int i = 1; i <= A.n; ++i) d10[i] = d10[i-1]*10;
    for (int i = 1; i <= A.n; ++i) f10[i] = d10[i-1]*i;
    solve();
}
