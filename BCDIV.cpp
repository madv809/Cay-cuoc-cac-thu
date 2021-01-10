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
const int INF = 1e9;
const LL BASE = 311;
ULL f[27][27];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(i, 1, 25) f[i][1] = 1;
    REP(j, 2, 25) REP(i, 2, 25) f[i][j] = f[i - 1][j - 1] + f[i - 1][j]*(ULL)j;
 
    int t, n, k; cin >> t;
    REP(i, 1, t)
    {
        cin >> n >> k;
        cout << f[n][k] << endl;
    }
}
 
