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
#include <queue>

using namespace std;
int n, m;
struct node
{
    LL val, lazy;
} it[200001];

void down (int id)
{
    LL t = it[id].lazy;

    it[id*2].val += t;
    it[id*2].lazy += t;

    it[id*2+1].val += t;
    it[id*2+1].lazy += t;

    it[id].lazy = 0;
}

void update (int id, int l, int r, int u, int v, LL val)
{
    if (v < l || r < u) return;
    if (u <= l && r <= v)
    {
        it[id].val += val;
        it[id].lazy += val;
        return;
    }

    int mid = (l + r)>>1;
    down(id);
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    it[id].val = max(it[id*2].val, it[id*2+1].val);
}

LL get (int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return -99999999;
    if (u <= l && r <= v) return it[id].val;

    int mid = (l + r)>>1;
    down(id);
    return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v, x; LL c;
    REP(i, 1, m)
    {
        scanf("%d", &x);
        if (x)
        {
            scanf("%d%d", &u, &v);
            printf("%lli\n", get(1, 1, n, u, v));
        }
        else
        {
            scanf("%d%d%lli", &u, &v, &c);
            update(1, 1, n, u, v, c);
        }
    }
}
