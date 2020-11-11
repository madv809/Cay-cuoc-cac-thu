#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define ii pair<int, int>

using namespace std;
const LL INF = 999999999;
LL dp[10001];
int n;
struct ed
{
    LL x, y;
} a[10001];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%lli%lli", &a[i].x, &a[i].y);
    for (int j = 1; j <= n; ++j) dp[j] = INF;

    REP(i, 1, n)
    {
        for (int j = i/2; j >= 1; --j)
            dp[j] = min(dp[j] + a[i].y, dp[j - 1] + a[i].x);
        dp[0] += a[i].y;
    }

    printf("%lli", dp[n/2]);
}
