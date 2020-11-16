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
    int n;
    int a[2304];

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

BigN operator + (const BigN &A, const BigN &B)
{
    BigN R;
    R = 0; int k = max(A.n, B.n);
    R.resize(k + 1);
    for (int i = 0; i < k; ++i) R[i] = A[i] + B[i];
    R.normalize();
    return R;
}

BigN operator - (const BigN &A, const BigN &B)
{
    BigN R;
    R = 0; int k = max(A.n, B.n);
    R.resize(k);
    for (int i = 0; i < k; ++i) R[i] = A[i] - B[i];
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

bool operator > (const BigN &A, const BigN &B)
{
    if (A.n != B.n) return (A.n > B.n);
    for (int i = A.n - 1; i >= 0; --i) if (A[i] != B[i]) return (A[i] > B[i]);
    return 0;
}

istream &operator >> (istream &cin, BigN &A)
{
    string s;
    cin >> s;
    int k = s.length(), x;
    A = 0; A.resize(k/4 + 1);
    for (int i = 0; i < k; ++i)
    {
        x = (k - 1 - i)/4;
        A[x] = A[x]*10 + (s[i] - '0');
    }
    A.normalize();
    return cin;
}

ostream &operator << (ostream &cout, const BigN &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}

int a[301], n, k;
BigN A, B;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> A >> B;
    //cout << (B) << ' ' <<  (A) << ' ' << (B - A); return 0;
    if (A > B)
    {
        cout << (A + B) << endl;
        cout << (A - B) << endl;
        cout << (A * B);
    }
    else
    {
        cout << (A + B) << endl;
        BigN C;
        C = B - A;
        if (C.n == 1 && C[0] == 0) cout << 0 << endl;
        else cout << '-' << C << endl;
        cout << (A*B);
    }
}
