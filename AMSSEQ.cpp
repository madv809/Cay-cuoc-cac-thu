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
int a[mxn], f[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, k; cin >> n >> k;
    REP(i, 1, n) cin >> a[i];
    REP(i, 1, n)
    {
        f[i] = -INF;
        for (int j = 1; j <= k && i - j >= 0; ++j)
            f[i] = max(f[i], f[i - j] + a[i]);
    }
    int res = 0;
    REP(i, 1, n) res = max(res, f[i]);
    cout << res;
}
