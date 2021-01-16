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
 
const int mxn = 2e5 + 5;
const ULL INF = 1e18 + 5;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
pLi a[mxn];
int dp[101][mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) {scanf("%lli", &a[i].X); a[i].Y = i;}
    sort(a + 1, a + n + 1);
    REP(i, 1, 100) REP(j, 1, n) dp[i][j] = 1;
    int res = 0;
    REP(d, 1, 100)
    {
        int x = 1;
        REP(i, 1, n)
        {
            while (x < i && a[x].X + d < a[i].X) ++x;
            while (a[x + 1].X + d == a[i].X && a[x + 1].Y < a[i].Y) ++x;
            if (a[x].X + d == a[i].X && a[x].Y < a[i].Y) dp[d][i] = dp[d][x] + 1;
            res = max(res, dp[d][i]);
        }
    }
    cout << res;
}
