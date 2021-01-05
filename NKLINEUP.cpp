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

const int mxn = 1e5 + 5;
const int INF = 1e9;
const LL BASE = 311;
int a[mxn], sp_min[mxn][30], sp_max[mxn][30];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, q; cin >> n >> q;
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n) sp_min[i][0] = sp_max[i][0] = a[i];
    int log2n = (int)log2(n);
    REP(j, 1, log2n) REP(i, 1, n)
    {
        int x = i + (1 << (j - 1));
        sp_min[i][j] = sp_min[i][j - 1];
        sp_max[i][j] = sp_max[i][j - 1];
        if (x <= n)
        {
            sp_min[i][j] = min(sp_min[i][j], sp_min[x][j - 1]);
            sp_max[i][j] = max(sp_max[i][j], sp_max[x][j - 1]);
        }
    }

    REP(i, 1, q)
    {
        int u, v; scanf("%d%d", &u, &v);
        int x = (int)log2(v - u + 1);
        int j = v - (1 << x) + 1;
        cout << max(sp_max[u][x], sp_max[j][x]) - min(sp_min[u][x], sp_min[j][x]) << endl;
    }
}
