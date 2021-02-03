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
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
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
 
using namespace std;
const int mxn = 2e2 + 5;
const LL INF = 1e18;
const int BASE = 10000;
struct BigN
{
    int a[105], n;
    void resize(int x) { n = x; FOR(i, 0, n) a[i] = 0; }
    void trim() { while (n > 1 && a[n - 1] == 0) --n; }
    void normalize()
    {
        for (int i = 0; i < n - 1; ++i)
        {
            a[i + 1] += a[i]/BASE;
            a[i] %= BASE;
            if (a[i] < 0)
            {
                --a[i + 1];
                a[i] += BASE;
            }
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
 
    void operator = (const BigN &A)
    {
        n = A.n;
        FOR(i, 0, n) a[i] = A[i];
    }
};
 
BigN operator + (BigN A, BigN B)
{
    ++A.n; A[A.n - 1] = 0;
    ++B.n; B[B.n - 1] = 0;
    if (A.n >= B.n)
    {
        FOR(i, 0, B.n) A[i] += B[i];
        A.normalize();
        return A;
    }
    FOR (i, 0, A.n) B[i] += A[i];
    B.normalize();
    return B;
}
 
BigN operator * (BigN A, const int &x)
{
    ++A.n; A[A.n - 1] = 0;
    FOR(i, 0, A.n) A[i] *= x;
    A.normalize();
    return A;
}
 
ostream &operator << (ostream &cout, const BigN &A)
{
    cout << A[A.n - 1];
    for (int i = A.n - 2; i >= 0; --i) printf("%04d", A[i]);
    return cout;
}
 
bool operator > (const BigN &A, const BigN &B)
{
    if (A.n != B.n) return (A.n > B.n);
    for (int i = A.n - 1; i >= 0; --i) if (A[i] != B[i]) return (A[i] > B[i]);
    return 0;
}
 
BigN f[mxn][mxn], g[mxn][mxn], dp[mxn][mxn];
LL h[mxn], sum[mxn], bmi, bmx, m;
bool vis[mxn][mxn];
int n, s, w;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    n = 200;
    REP(i, 0, n) REP(j, 0, n) f[i][j] = 0;
    REP(i, 0, n) f[i][0] = 1;
    REP(j, 1, n) REP(i, j, n) f[i][j] = f[i - 1][j]*(j + 1) + f[i - 1][j - 1]*(i - j);
    REP(i, 0, n) REP(j, 0, n) g[i][j] = 0;
    REP(i, 0, n) g[i][0] = 1;
    REP(i, 1, n) REP(j, 1, n) g[i][j] = g[i][j - 1] + f[i][j];
 
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> s >> w >> m >> bmi >> bmx;
        REP(i, 1, n) cin >> h[i];
 
        REP(i, 0, n) REP(j, 0, s) { vis[i][j] = 0; dp[i][j] = 0; }
 
        REP(i, 1, n) sum[i] = sum[i - 1] + h[i];
        vis[0][0] = 1;
        REP(j, 1, s) REP(i, j, n)
        {
            for (int k = i; k >= 1; --k)
            {
                if ((sum[i] - sum[k - 1])*m < bmi) continue;
                if ((sum[i] - sum[k - 1])*m > bmx) break;
 
                if (vis[k - 1][j - 1] && dp[k - 1][j - 1] + g[i - k + 1][w] > dp[i][j])
                {
                    vis[i][j] = 1;
                    dp[i][j] = dp[k - 1][j - 1] + g[i - k + 1][w];
                }
            }
        }
 
        cout << dp[n][s] << endl;
    }
}

/* Bài này đoạn nhân Big Num với số nguyên sai sml ngồi debug như ch*:))
đánh dấu mảng vis[i][j] để tránh th ta chọn 1 phân đoạn "ảo" không có thật*/
 
