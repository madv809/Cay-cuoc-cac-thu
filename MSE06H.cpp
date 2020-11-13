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
int n, m, k;
ii a[1000001];
LL bit[1001];

void up (int x)
{
    while (x)
    {
        ++bit[x];
        x -= x&(-x);
    }
}

LL get (int x)
{
    LL res = 0;
    while (x <= m)
    {
        res += bit[x];
        x += x&(-x);
    }
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    REP(j, 1, t)
    {
        scanf("%d%d%d", &n, &m, &k);
        REP(i, 1, k) scanf("%d%d", &a[i].X, &a[i].Y);
        sort(a + 1, a + k + 1);

        memset(bit, 0, sizeof(bit));
        LL res = 0;
        REP(i, 1, k)
        {
            res += get(a[i].Y + 1);
            up(a[i].Y);
        }
        printf("Test case %d: %lli \n", j, res);
    }
}
