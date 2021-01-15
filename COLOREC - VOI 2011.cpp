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
 
const int mxn = 5e2 + 5;
const ULL INF = 1e18 + 5;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
LL f[100];
int a[mxn][mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        u += 200; v += 200;
        a[u][v] = c;
    }
 
    LL res = 0;
    REP(i, 0, 400) REP(j, 0, 400)
    {
        memset(f, 0, sizeof(f));
        REP(k, 0, 400)
        {
            if (a[k][i] == 0 || a[k][j] == 0 || a[k][i] == a[k][j]) continue;
            int x = (1 << a[k][i]); x |= (1 << a[k][j]); x >>= 1;
            res += f[((1 << 4) - 1) ^ x];
            int kk = (((1 << 4) - 1) ^ x);
            f[x] += 1;
        }
    }
    cout << res/2;
}
 
