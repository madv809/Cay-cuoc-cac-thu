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
class BigNum
{
public :
    int n = 0;
    int a[1001];

    int& operator [] (int i) {return a[i];}
    const int operator [] (int i) const {return a[i];}

    void resize (int N)
    {
        for (int i = n; i < N; ++i) a[i] = 0;
        n = N;
    }

    void clear () {n = 0;}
    void trim () {while (n > 1 && a[n - 1] == 0) --n;}
    void normalize ()
    {
        for (int i = 1; i < n; ++i)
        {
            a[i] += a[i - 1]/BASE;
            a[i - 1] %= BASE;
            if (a[i - 1] < 0)
            {
                a[i - 1] += BASE;
                --a[i];
            }
        }
        trim();
    }

    void operator = (int x)
    {
        a[0] = x;
        n = 1;
    }

    void operator += (const BigNum &A)
    {
        resize(max(n, A.n) + 1);
        for (int i = 0; i < A.n; ++i) a[i] += A[i];
        normalize();
    }

    void operator -= (const BigNum &A)
    {
        for (int i = 0; i < A.n; ++i) a[i] -= A[i];
        normalize();
    }
};


BigNum operator * (const BigNum &A, const BigNum &B)
{
    BigNum R;
    R.resize(A.n + B.n);
    for (int i = 0; i < A.n; ++i)
        for (int j = 0; j < B.n; ++j) R[i + j] += A[i]*B[j];
    R.normalize();
    return R;
}

BigNum operator * (const BigNum &A, int x)
{
    BigNum R;
    R.clear(); R.resize(A.n + 1);
    for (int i = 0; i < A.n; ++i) R[i] = A[i]*x;
    R.normalize();
    return R;
}

ostream &operator << (ostream &cout, const BigNum &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}

istream &operator >> (istream &cin, BigNum &A)
{
    string s;
    cin >> s;
    int k = s.length(), x;
    A.clear(); A.resize(k/4 + 1);
    for (int i = 0; i < s.length(); ++i)
    {
        x = (k - 1 - i)/4;
        A[x] = A[x]*10 + (s[i] - '0');
    }
    A.normalize();
    return cin;
}

bool operator > (BigNum A, BigNum B)
{
    if (A.n != B.n) return (A.n > B.n);
    for (int i = A.n - 1; i >= 0; --i) if (A[i] != B[i]) return (A[i] > B[i]);
    return 0;
}

int n, k;
BigNum f[101], S;
bool b[101];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    cin >> S;
    f[0] = 1;
    REP(i, 1, k) f[i] = f[i - 1]*(n - k + i);
    //REP(i, 1, k) cout << f[i] << ' ';
    //cout << S << ' ' << S.n << ' ' << f[0] << ' ' << f[0].n << endl;
    //cout << (S > f[1]) << endl;

    int d = k - 1, c = 0;
    while (1)
    {
        REP(i, 1, n) if (!b[i])
        {
            if (S > f[d]) S -= f[d];
            else
            {
                printf("%d ", i);
                b[i] = 1;
                --d;
                break;
            }
        }
        if (d == -1) break;
    }
    printf("\n");
    memset(b, 0, sizeof(b));

    int a[101]; S = 1; d = k;
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n)
    {
        REP(j, 1, n) if (!b[i])
        {
            if (j == a[i]) {--d; break;}
            S += f[d - 1];
        }
        if (d == 0) break;
    }
    cout << S;
}
