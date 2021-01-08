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
int a[mxn];
set<int> s;
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n) {int x; scanf("%d", &x); s.insert(x);}
    LL res = INF;
    REP(i, 1, n)
    {
        auto it = s.lower_bound(-a[i]);
        if (it != s.end()) res = min(res, (LL)abs(a[i] + *it));
        if (it != s.begin()) --it;
        res = min(res, (LL)abs(a[i] + *it));
    }
    cout << res;
}
