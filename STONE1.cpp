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
int dp[401], n;
vector <int> a[401];

void go (int u)
{
    if (a[u].size() == 0)
    {
        dp[u] = 1;
        return;
    }

    vector <int> aa;
    for (int v : a[u])
    {
        go(v);
        aa.push_back(dp[v]);
    }
    sort(aa.begin(), aa.end());

    int maxx = aa[aa.size() - 1];
    int tmp = maxx - 1;
    for (int i = aa.size() - 2; i >= 0; --i)
    {
        if (tmp < aa[i])
        {
            ++maxx;
            ++tmp;
        }
        --tmp;
    }
    dp[u] = maxx;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int u, v, m;
    while (scanf("%d", &u) > 0)
    {
        scanf("%d", &m);
        REP(i, 1, m)
        {
            scanf("%d", &v);
            a[u].push_back(v);
        }
    }

    go(1);
    printf("%d", dp[1]);
}
