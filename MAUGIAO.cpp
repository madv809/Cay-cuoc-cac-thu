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
const int mxn = 2e2 + 5;
const LL INF = 1e18;
const int BASE = 10000;
LL f[22][1<<20], inc[mxn][mxn];
int c_f[22][1 << 20], n;
 
LL Solve (int i, int state)
{
    LL &ans = f[i][state];
    if (ans != -1) return ans;
    FOR(k, 0, n) if (state &(1 << k))
    {
        int tmp = state^(1 << k);
        if (ans < Solve(i + 1, tmp) + inc[i][k])
        {
            ans = f[i + 1][tmp] + inc[i][k];
            c_f[i][state] = c_f[i + 1][tmp];
        }
        else if (ans == f[i + 1][tmp] + inc[i][k]) c_f[i][state] += c_f[i + 1][tmp];
    }
    return ans;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    FOR(i, 0, n) FOR(j, 0, n) cin >> inc[i][j];
    memset(f, -1, sizeof(f));
    f[n][0] = 0;
    c_f[n][0] = 1;
    cout << Solve(0, (1 << n) - 1) << ' ' << c_f[0][(1 << n) - 1];
}
 
