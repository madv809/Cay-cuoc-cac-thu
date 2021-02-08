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
const int mxn = 1094783;
const LL INF = 1e18;
const LL MOD = 790972;
const int BASE = 10000;
 
LL a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n)
    {
        LL x;
        scanf("%lli", &x);
        a[i] = a[i - 1] + x;
    }
 
    LL res = -INF;
    LL x1 = 0, x2 = 0;
    REP(i, 1, n)
    {
        if (i < n) res = max(res, a[i] - x2);
        if (i > 1) res = max(res, a[n] - a[i - 1] + x1);
        x1 = max(x1, a[i - 1]);
        x2 = min(x2, a[i]);
    }
    cout << res;
}
 
