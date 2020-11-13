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
int number[10001], low[10001], n, m, k, res;
vector <int> a[10001], sta;
bool fr[10001];

void dfs (int u)
{
    number[u] = low[u] = ++k;
    sta.pb(u);
    for (int v : a[u]) if (!fr[v])
    {
        if (number[v]) low[u] = min(low[u], number[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if (low[u] == number[u])
    {
        ++res; int x;
        while (sta.size())
        {
            x = sta.back();
            fr[x] = 1;
            sta.pop_back();
            if (x == u) break;
        }
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v;
    REP(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        a[u].pb(v);
    }

    REP(i, 1, n) if (!fr[i]) dfs(i);
    printf("%d", res);
}
