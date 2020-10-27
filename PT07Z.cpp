#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;
int dp[10001][2], vist[10001], n, t;
vector <int> a[10001];

void go(int par, int u)
{
    for (int v : a[u]) if (v != par)
    {
        go(u, v);
        dp[u][0] = max(max(dp[u][0], dp[u][1] + dp[v][1] + 1), dp[v][0]);
        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int u, v;
    FOR(i, 1, n)
    {
        scanf("%d%d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    go(0, 1);

    int res = max(dp[1][0], dp[1][1]);
    printf("%d", res);
}
