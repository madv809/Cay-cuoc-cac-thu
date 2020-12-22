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

const int mxn = 1e6 + 5;
const int INF = 1e9;
int a[mxn], f[mxn], g[mxn], bit[mxn], n;
pii tmp[mxn];

void up (int x, int val)
{
    while (x <= n)
    {
        bit[x] = max(bit[x], val);
        x += x&-x;
    }
}

int get (int x)
{
    int res = 0;
    while (x)
    {
        res = max(res, bit[x]);
        x -= x&-x;
    }
    return res;
}

void upp (int x, int val)
{
    while (x)
    {
        bit[x] = max(bit[x], val);
        x -= x&-x;
    }
}

int gett (int x)
{
    int res = 0;
    while (x <= n)
    {
        res = max(res, bit[x]);
        x += x&-x;
    }
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    REP(i, 1, n) {cin >> a[n - i + 1]; tmp[n - i + 1].X = a[n - i + 1]; tmp[n - i + 1].Y = n - i + 1;}
    sort(tmp + 1, tmp + n  + 1);
    int k = 1; a[tmp[1].Y] = 1;
    REP(i, 2, n)
    {
        if (tmp[i].X != tmp[i-1].X) ++k;
        a[tmp[i].Y] = k;
    }
    REP(i, 1, n)
    {
        f[i] = get(a[i] - 1) + 1;
        up(a[i], f[i]);
    }
    memset(bit, 0, sizeof(bit));
    REP(i, 1, n)
    {
        g[i] = gett(a[i] + 1) + 1;
        upp(a[i], g[i]);
    }
    int res = 0;
    REP(i, 1, n) res = max(res, f[i] + g[i]);
    cout << res - 1 << endl;
}
