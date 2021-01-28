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
const int mxn = 1e3 + 5;
const LL INF = 1e18;
LL f[mxn][mxn][2], c[mxn][mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int t; cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        REP(i, 0, n) REP(j, 0, m) f[i][j][0] = f[i][j][1] = 0;
        REP(i, 1, n) REP(j, 1, m)
        {
            LL x;
            scanf("%lli", &x);
            c[i][j] = x;
        }
 
        REP(i, 1, n) REP(j, 1, m)
        {
            f[i][j][0] = min(j == 1 ? c[i][j] : f[i][j - 1][0], f[i][j - 1][1] + c[i][j]);
            f[i][j][1] = min(i == 1 ? c[i][j] : f[i - 1][j][1], f[i - 1][j][0] + c[i][j]);
        }
 
        cout << min(f[n][m][0], f[n][m][1]) << endl;
    }
}
