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
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>

using namespace std;
int n, m;
bool vist[2001];
vector <int> a[2001];

void dfs (int u)
{
    vist[u] = 1;
    for (int v : a[u]) if (!vist[v]) dfs(v);
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d%d", &n, &m); int u, v, k = 0;
    REP(i, 1, m) {scanf("%d%d", &u, &v); a[u].pb(v); a[v].pb(u);}
    REP(i, 1, n) if (!vist[i]){++k; dfs(i);}
    printf("%d", m - n + k);
}
