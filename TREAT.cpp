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
const int mxn = 1e5 + 5;
const LL INF = 1e18;
int nxt[mxn], en[mxn], f[mxn], vis[mxn];
vector<int> st;
 
void dfs(int u)
{
    st.pb(u);
    int v = nxt[u];
    if (vis[v])
    {
        if (!en[v])
        {
            int x, k = vis[st.back()] - vis[v] + 1;
            do
            {
                x = st.back();
                st.pop_back();
                f[x] = k;
            } while (x != v);
        }
        else f[u] = 1 + f[v];
    }
    else
    {
        vis[v] = vis[u] + 1;
        dfs(v);
        if (!f[u]) f[u] = 1 + f[v];
    }
    en[u] = 1;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) scanf("%d", &nxt[i]);
    REP(i, 1, n) if (!vis[i]) { st.clear(); vis[i] = 1; dfs(i); }
    REP(i, 1, n) printf("%d\n", f[i]);
}
 
