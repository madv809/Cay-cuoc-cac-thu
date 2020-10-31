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
int dp[1001], a[1001], n;
vector <int> aa[1001];
bool p[1001][1001];

int findd (int u, int v)
{
    int l = v + 1, r = n, x = a[u] + a[v];

    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (a[mid] == x) return mid;
        else if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    if (a[l] == x) return l;
    return 0;
}

int go (int u)
{
    if (dp[u] != -1) return dp[u];
    dp[u] = 1;
    for (int v : aa[u])
        dp[u] = max(dp[u], 1 + go(v));

    return dp[u];
}

void load ()
{
    for (int i = 1; i <= n - 2; ++i)
        for (int j = i + 1; j <= n - 1; ++j) if (int x = findd(i, j))
        {
            for (int k = x; k <= n && a[k] == a[x]; ++k)
            {
                if (!p[i][k])
                {
                    p[i][k] = 1;
                    aa[i].push_back(k);
                }
                if (!p[j][k])
                {
                    p[j][k] = 1;
                    aa[j].push_back(k);
                }
            }

            for (int k = x - 1; k >= 1 && a[k] == a[x]; --k)
            {
                if (!p[i][k])
                {
                    p[i][k] = 1;
                    aa[i].push_back(k);
                }
                if (!p[j][k])
                {
                    p[j][k] = 1;
                    aa[j].push_back(k);
                }
            }
        }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    load();

        memset(dp, -1, sizeof(dp));
        int best = 0;
        REP(i, 1, n) best = max(best, go(i));
        printf("%d\n", best);
}
