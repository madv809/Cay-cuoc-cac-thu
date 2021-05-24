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
#include <bitset>
#include <unordered_map>

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
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
#define lb lower_bound
#define even "even"
#define odd "odd"

using namespace std;
const int mxn = 3e3 + 5;
const int MOD = 1e9 + 7;
const int BASE = 10000;
const int INF = 1e17 + 123;
LL f[mxn][mxn], a[mxn], b[mxn], n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    REP(i, 1, n) cin >> a[i];
    for (int i = n; i >= 1; --i) b[i] = a[n - i + 1];

    LL res = -INF; bool ok = 0;
    FOR(i, 1, n)
        for (int j = 1; n - j >= i; ++j)
        {
            if (a[i]*b[j] + f[i - 1][j - 1] >= 0)
            {
                f[i][j] = a[i]*b[j] + f[i - 1][j - 1];
                ok = 1;
            }
            res = max(res, f[i][j]);
        }

    if (ok) cout << res;
    else
    {
        res = -INF;
        FOR(i, 1, n)
            for (int j = i + 1; j <= n; ++j)
                res = max(res, a[i]*a[j]);
        cout << res;
    }
    // 1 2 3 4 5
}
