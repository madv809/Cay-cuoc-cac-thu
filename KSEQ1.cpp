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
const int mxn = 3e2 + 5;
const LL INF = 1e9;
const LL MOD = 790972;
const int BASE = 10000;
 
int f[mxn][mxn], g[2][mxn], a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n;
    cin >> n;
    REP(i, 1, n) cin >> a[i];
 
    int res = 0;
    REP(l, 2, n)
    {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
 
        int x = 0;
        FOR(i, 1, l)
        {
            x ^= 1;
            int mx = 0;
            REP(j, l, n)
            {
                g[x^1][j] = g[x][j];
                if (a[i] < a[j]) f[i][j] = mx + 1;
                g[x^1][j] = max(g[x^1][j], f[i][j]);
                mx = max(mx, g[x][j]);
                res = max(res, f[i][j]);
            }
        }
    }
    cout << res;
}
 
