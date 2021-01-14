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
 
const int mxn = 2e6 + 5;
const LL INF = 1e18;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
int bit[mxn], n;
pii a[mxn];
 
void up (int x, int val)
{
    while (x)
    {
        bit[x] = max(bit[x], val);
        x -= x&-x;
    }
}
 
int get (int x)
{
    int res = 0;
    while (x <= 1e6)
    {
        res = max(res, bit[x]);
        x += x&-x;
    }
    return res;
}
 
bool cmpx (pii a, pii b)
{
    if (a.X < b.X) return 1;
    if (a.X == b.X) return (a.Y >= b.Y);
    return 0;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    REP(i, 1, n) cin >> a[i].X >> a[i].Y;
    sort(a + 1, a + n + 1, cmpx);
    int res = 0;
    REP(i, 1, n)
    {
        int x = get(a[i].Y) + 1;
        res = max(res, x);
        up(a[i].Y, x);
    }
    cout << res;
}
 
