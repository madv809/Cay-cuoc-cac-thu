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
    int val, lazy, state;
} it[200001];

void down (int id, int l, int mid, int r)
{
    int &t = it[id].lazy;

    it[id*2].state ^= t;
    it[id*2].lazy ^= t;
    if (it[id*2].state)
    {
        it[id*2].val = (mid - l + 1) - it[id*2].val;
        it[id*2].state = 0;
    }

    it[id*2+1].state ^= t;
    it[id*2+1].lazy ^= t;
    if (it[id*2+1].state)
    {
        it[id*2+1].val = (r - mid) - it[id*2+1].val;
        it[id*2+1].state = 0;
    }

    it[id].lazy = 0;
}

void update (int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return;
    if (u <= l && r <= v)
    {
        it[id].state ^= 1;
        it[id].lazy ^= 1;
        if (it[id].state)
        {
            it[id].val = (r - l + 1) - it[id].val;
            it[id].state = 0;
        }
        return;
    }

    int mid = (l + r)>>1;
    down(id, l, mid, r);
    update(id*2, l, mid, u, v);
    update(id*2+1, mid+1, r, u, v);
    it[id].val = it[id*2].val + it[id*2+1].val;
}

int get (int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return it[id].val;

    int mid = (l + r)>>1;
    down(id, l, mid, r);
    return (get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v, x;
    REP(i, 1, m)
    {
        scanf("%d%d%d", &x, &u, &v);
        if (x) printf("%d\n", get(1, 1, n, u, v));
        else update(1, 1, n, u, v);
    }
}
