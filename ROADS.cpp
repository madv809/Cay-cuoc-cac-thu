#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

using namespace std;
const int INF = 1000000009;
int d1[101], d2[101], n, k, r, t, best;
vector <int> a[101], b[101], l[101], c[101], lRe[101], cRe[101];
bool vist[101];

void dijsktra (int d[], vector <int> adj[], vector <int> c[])
{
    memset(vist, 0, sizeof(vist));
    FOR(i, 0, n) d[i] = INF;
    d[n] = 0;
    while (1)
    {
        int maxx = 0;
        FOR(i, 1, n) if (!vist[i] && d[i] < d[maxx]) maxx = i;
        if (maxx == 0) break;
        vist[maxx] = 1;
        for (int i = 0; i < adj[maxx].size(); ++i)
        {
            int v = adj[maxx][i];
            if (!vist[v] && d[v] > d[maxx] + c[maxx][i]) d[v] = d[maxx] + c[maxx][i];
        }
    }
}

void reset()
{
    FOR(i, 1, n)
    {
        a[i].clear();
        b[i].clear();
        l[i].clear();
        c[i].clear();
        lRe[i].clear();
        cRe[i].clear();
    }
    best = INF;
}

void go (int u, int lroad, int cw)
{
    if (lroad + d1[u] >= best || cw + d2[u] > k) return;
    if (u == n)
    {
        best = min(best, lroad);
        return;
    }
    vist[u] = 1;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (!vist[v]) go(v, lroad + l[u][i], cw + c[u][i]);
    }
    vist[u] = 0;
}

void load()
{
        int u, v, lt, ct;
        scanf("%d", &k);
        scanf("%d", &n);
        scanf("%d", &r);
        reset();
        FOR(i, 1, r)
        {
            scanf("%d%d%d%d", &u, &v, &lt, &ct);
            lRe[v].push_back(lt);
            cRe[v].push_back(ct);
            l[u].push_back(lt);
            c[u].push_back(ct);
            a[u].push_back(v);
            b[v].push_back(u);
        }
        dijsktra(d1, b, lRe);
        dijsktra(d2, b, cRe);
        memset(vist, 0, sizeof(vist));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    while(t--)
    {
        load();
        go(1, 0, 0);
        if (best != INF) printf("%d\n", best);
        else printf("-1\n");
    }
}
