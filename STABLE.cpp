#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>
 
#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = (a) - 1; i >= (b); --i)
#define REPD(i, a, b) for (int i = (a); i >= (b); --i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array
 
using namespace std;
 
const int mxn = 2e6 + 5;
const LL INF = 1e18;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
int d[mxn], re[mxn], n, m, s;
set<int> a[mxn];
 
void BFS()
{
    queue<int> sea;
    sea.push(s); d[s] = re[s] = 1;
 
    while (sea.size())
    {
        int u = sea.front(); sea.pop();
        for (int v : a[u]) if (!re[v])
        {
            re[v] = re[u];
            d[v] = d[u] + 1;
            sea.push(v);
        }
        else if (d[v] == d[u] + 1)
        {
            re[v] += re[u];
            if (re[v] > 2) re[v] = 2;
        }
    }
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m >> s;
    REP(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].insert(v);
    }
    BFS();
    int res = 0;
    REP(i, 1, n) if (re[i] == 2) ++res;
    cout << res;
}
 
