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
const int mxn = 2e5 + 5;
const LL INF = 1e18;
int low[mxn], num[mxn], lv[mxn], ct, t, n, m, res = 1;
vector<int> a[mxn], st;
 
void dfs (int p, int u)
{
    st.pb(u);
    low[u] = num[u] = ++t;
    for (int v : a[u]) if (v != p)
    {
        if (num[v]) { low[u] = min(low[u], num[v]); continue; }
        st.pb(u);
        dfs(u, v);
        low[u] = min(low[u], low[v]);
        if (low[v] >= num[u])
        {
            ++ct;
            int x, cm = 0;
            do{
                x = st.back();
                if (lv[x] != ct) { ++cm; lv[x] = ct; }
                st.pop_back();
            } while (x != u);
            res = max(res, cm);
        }
    }
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n >> m;
    REP(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u].pb(v); a[v].pb(u);
    }
 
    REP(i, 1, n) if (!num[i])
    {
        st.clear();
        dfs(0, i);
        //res = max(res, (int)st.size());
    }
    cout << res;
}
 
