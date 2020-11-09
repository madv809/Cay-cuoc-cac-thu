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
int a[60001], n;
LL bit[60001];

void update (int x)
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
    while (x <= 60000)
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
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d", &a[i]);

    LL res = 0;
    REP(i, 1, n)
    {
        res += get(a[i] + 1);
        update(a[i]);
    }

    printf("%lli", res);
}
