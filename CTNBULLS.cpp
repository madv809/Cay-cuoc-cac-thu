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
const int MOD = 2111992;
int f[mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, k; cin >> n >> k;
    int l = 1, x = 1; f[1] = 1;
    REP(i, 2, n)
    {
        if (i > k + 1) (x += f[l++]) %= MOD;
        f[i] = x;
    }
    int res = 0;
    REP(i, 1, n) (res += f[i]) %= MOD;
    //REP(i, 1, n) cout << f[i] << ' '; cout << endl;
    cout << (res + 1);
}
 
