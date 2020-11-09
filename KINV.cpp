#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define ii pair<int, int>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;
const LL MOD = 1000000000;
int a[10001], n, k;
LL dp[10001][11], bit[10001][11], res;

void update (int x, int k, LL val)
{
    while (x > 0)
    {
        bit[x][k] = (bit[x][k] + val)%MOD;
        x -= x&(-x);
    }
}

LL get (int x, int k)
{
    LL res = 0;
    while (x <= n)
    {
        res = (res + bit[x][k])%MOD;
        x += x&(-x);
    }
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    REP(i, 1, n) scanf("%d", &a[i]);
    REP(i, 1, n) dp[i][1] = 1;

    REP(j, 2, k) REP(i, 1, n)
    {
        dp[i][j] = get(a[i] + 1, j - 1);
        update(a[i], j - 1, dp[i][j - 1]);
    }

    REP(i, 1, n) res = (res + dp[i][k])%MOD;
    printf("%lli", res);
}
