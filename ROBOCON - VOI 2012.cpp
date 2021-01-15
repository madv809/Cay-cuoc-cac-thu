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
const int fx[2][3] = { { 1, 1, 0 }, { 1, 1, 0 } };
const int fy[2][3] = { { 0, -1, -1 }, { 0, 1, 1 } };
int yasuo[2][mxn][mxn], a[mxn][mxn], n, k;
queue<pii> yone[2];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> k; if (n == 1) {cout << 0; return 0;}
    REP(i, 1, k)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
    }
 
    yone[1].push({1, 1});
    yone[0].push({1, n});
 
    int rose = 1, res = 0;
    while (1)
    {
        if (rose) ++res;
        int x = yone[rose].size();
        while (x--)
        {
            int i = yone[rose].front().X, j = yone[rose].front().Y;
            yone[rose].pop();
 
            REP(k, 0, 2)
            {
                int u = i + fx[rose][k], v = j + fy[rose][k];
                yasuo[rose][i][j] = 0;
                if (u < 1 || u > n || v < 1 || v > n || a[u][v]) continue;
                if (!rose && yasuo[rose^1][u][v]) {cout << res; return 0;}
                yone[rose].push({u, v});
            }
        }
        x = yone[rose].size();
        while (x--)
        {
            int u = yone[rose].front().X, v = yone[rose].front().Y;
            yone[rose].pop();
            if (!yasuo[rose][u][v])
            {
                yone[rose].push({u, v});
                yasuo[rose][u][v] = 1;
            }
        }
        rose ^= 1;
    }
}
 
