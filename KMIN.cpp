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
int m, n, k;
LL a[50001], b[50001];
vector <LL> res;

struct cmp
{
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return (a[x.X] + b[x.Y] > a[y.X] + b[y.Y]);
    }
};

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    REP(i, 1, m) scanf("%lli", &a[i]);
    REP(i, 1, n) scanf("%lli", &b[i]);
    sort(a + 1, a + m + 1);
    priority_queue <pair<int, int> , vector<pair<int, int> >, cmp> heap;
    REP(i, 1, n) heap.push({1, i});

    REP(i, 1, k)
    {
        pair<int, int> u = heap.top();
        res.push_back(a[u.X] + b[u.Y]);
        heap.pop();
        if (u.X != n) heap.push({u.X + 1, u.Y});
    }

    for (LL i : res) printf("%lli\n", i);
}
