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
 
const int mxn = 2e5 + 5;
const LL INF = 1e18;
const LL BASE = 311;
LL a[mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m; cin >> n >> m;
    REP(i, 1, m) cin >> a[i];
    sort(a + 1, a + m + 1);
    int i;
    if (m <= n) i = 1;
    else i = m - n + 1;
    LL res = 0, kk;
    for ( ; i <= m; ++i) if (res < a[i]*(m - i + 1))
    {
        res = a[i]*(m - i + 1);
        kk = a[i];
    }
    cout << kk << ' ' << res;
}
