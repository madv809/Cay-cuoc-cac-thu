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
const int BASE = 100000;
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
    A = 0; A.resize(k/5 + 1);
    for (int i = 0; i < k; ++i)
    {
        x = (k - 1 - i)/5;
        A[x] = A[x]*10 + (s[i] - '0');
    }
    A.normalize();
    return cin;
}
 
ostream &operator << (ostream &cout, const BigN &A)
{
    printf("%d", A[A.n - 1]);
    for (int i = A.n - 2; i >= 0; --i) printf("%05d", A[i]);
    return cout;
}
 
int a[301], n, k;
BigN C[301][301], S;
bool used[301];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, 0, n) {C[i][1] = i; C[0][i] = 0;}
    REP(j, 2, k) REP(i, 1, n) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    REP(i, 0, n) {C[0][i] = 1; C[i][0] = 1;}
    cin >> S;
    REP(i, 1, k) scanf("%d", &a[i]);
 
    int kk = k - 1, nn = n - 1;
        REP(i, 1, n)
        {
            if (S > C[nn][kk]) S = S - C[nn][kk];
            else
            {
                printf("%d ", i);
                --kk;
            }
            --nn;
            if (kk == -1) break;
        }
    printf("\n");
 
    BigN P; P = 1; nn = n - 1; kk = k - 1;
    REP(i, 1, k)
    {
        REP(j, 1, n) if (!used[j])
        {
            if (a[i] == j)
            {
                used[j] = 1;
                --kk;
                --nn;
                break;
            }
            used[j] = 1;
            P = P + C[nn][kk];
            --nn;
        }
    }
    cout << P << endl;
}
