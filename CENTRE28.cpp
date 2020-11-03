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
int q[30001], s[30001], pos[30001], heap[2*30005], nheap, n, m;
vector <int> a[30001];
vector <LL> c[30001];
LL d1[30001], d2[30001], f1[30001], f2[30001];
bool inq[30001], vist[30001];

void up (LL d[], int u)
{
    int child = pos[u], par;
    if (child == 0)
        child = ++nheap;

    par = child/2;

    while (par)
    {
        if (d[heap[par]] <= d[u]) break;
        heap[child] = heap[par];
        pos[heap[child]] = child;
        child = par;
        par /= 2;
    }
    heap[child] = u;
    pos[u] = child;
}

int pop (LL d[])
{
    int x = heap[1], u = heap[nheap--];
    int par = 1, child = 2;

    while (child <= nheap)
    {
        if (child + 1 <= nheap && d[heap[child + 1]] < d[heap[child]])
            ++child;
        if (d[heap[child]] >= d[u]) break;
        heap[par] = heap[child];
        pos[heap[par]] = par;
        par = child;
        child *= 2;
    }

    heap[par] = u;
    pos[u] = par;

    return x;

}

void BF (LL d[], LL f[], int s)
{
    REP(i, 1, n) d[i] = 999999999;
    //memset(inq, 0, sizeof(inq));
    memset(pos, 0, sizeof(pos));
    memset(vist, 0, sizeof(vist));

    d[s] = 0;
    f[s] = 1;
    up(d, s);

    while (nheap)
    {
        int u = pop(d);
        vist[u] = 1;

        for (int i = 0; i < a[u].size(); ++i)
        {
            int v = a[u][i];
            if (vist[v]) continue;
            if (d[v] > d[u] + c[u][i])
            {
                d[v] = d[u] + c[u][i];
                f[v] = f[u];
                up(d, v);
            }
            else if (d[v] == d[u] + c[u][i])
                f[v] += f[u];
        }
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    int u, v; LL w;
    REP(i, 1, m)
    {
        scanf("%d%d%lli", &u, &v, &w);
        a[u].push_back(v);
        a[v].push_back(u);
        c[u].push_back(w);
        c[v].push_back(w);
    }
    BF(d1, f1, 1);
    BF(d2, f2, n);

    int res = n - 2;
    FOR(i, 2, n) if (d1[i] + d2[i] == d1[n] && f1[i]*f2[i] == f1[n])
    {
        --res;
        s[i] = 1;
    }

    printf("%d\n", res);
    FOR(i, 2, n) if (!s[i]) printf("%d\n", i);
    /*REP(i, 1, n) cout << d1[i] << ' ';
    cout << endl;
    REP(i, 1, n) cout << d2[i] << ' ';
    cout << endl;
    REP(i, 1, n) cout << f1[i] << ' ';*/
}
