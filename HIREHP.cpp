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
const LL INF = 9e30;
int n;
LL f[500001];
struct ed
{
    LL p, t;
} a[500001];

struct cmp
{
    bool operator () (int u, int v)
    {
        return (f[u - 1] + a[u].p > f[v - 1] + a[v].p);
    }
};

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%lli%lli", &a[i].t, &a[i].p);

    priority_queue <int, vector<int>, cmp> q;
    f[1] = a[1].p; q.push(1);

    REP(i, 2, n)
    {
        while (q.size() && a[q.top()].t < i) q.pop();
        if (q.size())
        {
            int u = q.top();
            f[i] = min(f[i - 1] + a[i].p, f[u - 1] + a[u].p);
        }
        else f[i] = f[i - 1] + a[i].p;
        q.push(i);
    }

    printf("%lli", f[n]);
}
