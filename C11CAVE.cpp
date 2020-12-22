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
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array

using namespace std;

const int mxn = 2e6 + 5;
const int INF = 1e9;
int f[mxn], g[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, h; cin >> n >> h;
    int k = 1;
    REP(i, 1, n)
    {
        int x; cin >> x;
        if (k) f[x] += 1;
        else g[x] += 1;
        k ^= 1;
    }
    for (int i = h - 1; i >= 1; --i) {f[i] += f[i+1]; g[i] += g[i+1];}
    int res = INF, x = 0;
    REP(i, 1, h)
    {
        if (res > f[i] + g[h - i + 1])
        {
            res = f[i] + g[h - i + 1];
            x = 1;
        }
        else if (res == f[i] + g[h - i + 1]) ++x;
    }
    cout << res << ' ' << x;
}
