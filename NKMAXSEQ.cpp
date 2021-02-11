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
const LL INF = 1e18;
const LL MOD = 790972;
const int BASE = 10000;
 
pLi a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; LL p;
    cin >> n >> p;
    REP(i, 1, n)
    {
        LL x;
        scanf("%lli", &x);
        a[i].X = a[i - 1].X + x;
        a[i].Y = i;
    }
    a[0].X = a[0].Y = 0;
    sort(a, a + n + 1);
 
    int j = 0, x = 0, res = 0;
    REP(i, 0, n)
    {
        while (a[i].X - a[j].X >= p && j < n)
        {
            ++j;
            if (a[i].X - a[j].X >= p && a[x].Y > a[j].Y) x = j;
        }
        if (j != 0) --j;
        if (a[i].X - a[x].X >= p) res = max(res, a[i].Y - a[x].Y);
    }
    cout << ((res > 0) ? res : -1);
}
 
