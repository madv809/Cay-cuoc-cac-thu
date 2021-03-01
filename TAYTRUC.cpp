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
#define ef else if

using namespace std;
const int mxn = 1e4 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
LL f[mxn][505][3], a[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    REP(i, 1, n) cin >> a[i];

    REP(i, 1, n) for (int j = 0; j <= min(i, m); ++j)
    {
        f[i][j][0] = max(f[i - 1][j][0], max(f[i - 1][j][1], f[i - 1][j][2]));
        if (j != 0)
        {
            if (j == 1) f[i][1][1] = max(f[i - 1][0][0], f[i - 1][0][2]) + a[i];
            else f[i][j][1] = f[i - 1][j - 1][1] + a[i];
        }
        if (j < min(i, m))
            f[i][j][2] = max(f[i - 1][j + 1][2], max(f[i - 1][j + 1][1], f[i - 1][j + 1][0]));
    }

    cout << max(f[n][0][0], f[n][0][2]);
}

