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
int n, nn;
LL bit[100001];
vector <int> a[100001];
struct ed
{
    int l, r;
    LL val;
}c[100001];

void dfs (int u)
{
    if (a[u].size() == 0)
    {
        c[u].l = c[u].r = nn--;
        return;
    }
    for (int v : a[u])
    {
        dfs(v);
        c[u].r = max(c[u].r, c[v].r);
    }
    c[u].l = nn--;
}

void up (int x)
{
    while (x <= n)
    {
        ++bit[x];
        x += x&(-x);
    }
}

LL gett (int x)
{
    LL res = 0;
    while (x)
    {
        res += bit[x];
        x -= x&(-x);
    }
    return res;
}

LL get (int l, int r)
{
    return (gett(r) - gett(l - 1));
}

bool cmp (ed a, ed b)
{
    return (a.val < b.val);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n); nn = n; scanf("%lli", &c[1].val);
    int u; LL w;
    REP(i, 2, n)
    {
        scanf("%d%lli", &u, &w);
        a[u].pb(i); c[i].val = w;
    }

    dfs(1);
    sort(c + 1, c + n  + 1, cmp);
    LL res = 0, countt;
    int k = 1;
    REP(i, 2, n)
    {
        for (; c[k].val < c[i].val; ++k) up(c[k].l);
        countt = get(c[i].l, c[i].r);
        res += countt*(countt - 1)/2;
    }
    //REP(i, 1, n) cout << c[i].l << ' ' << c[i].r << endl;
    printf("%lli", res);
}
