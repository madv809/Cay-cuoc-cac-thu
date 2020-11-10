#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define ii pair<int, int>
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
int res[100001], n;
struct ed
{
    int p, d, t;
} a[100001];

bool cmpp (ed a, ed b){return (a.d < b.d);}

struct cmp{bool operator()(int x, int y){return (a[x].p < a[y].p);}};

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) {scanf("%d", &a[i].p); a[i].t = i;}
    REP(i, 1, n) scanf("%d", &a[i].d);
    sort(a + 1, a + n + 1, cmpp);

    priority_queue<int, vector<int>, cmp> q;
    memset(res, 1, sizeof(res));
    int time = 0, nres = 0;
    REP(i, 1, n)
    {
        time += a[i].p;
        q.push(i);
        if (time>a[i].d)
        {
            int u = q.top(); q.pop();
            time -= a[u].p;
            res[a[u].t] = 0;
            ++nres;
        }
    }

    printf("%d\n", nres);
    REP(i, 1, n) if (res[a[i].t]) printf("%d ", a[i].t);
    REP(i, 1, n) if (!res[a[i].t]) printf("%d ", a[i].t);
}
