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
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    LL f = 0, g = 0; LL res = -INF;
    REP(i, 1, n)
    {
        LL x; scanf("%lli", &x);
        LL tmp = f;
        f = max(f, g + x);
        g = max(g, tmp - x);
        res = max(res, max(f, g));
    }
    cout << res;
}
 
