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
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array

using namespace std;

const int mxn = 1e5+1;
vector<int> aa[2*mxn + 5], st;
vector<int> *a = &aa[mxn + 1];
int n, m, nnum[2*mxn + 5], llow[2*mxn + 5], WW[2*mxn + 5], t;
int *W = &WW[mxn + 1], *num = &nnum[mxn + 1], *low = &llow[mxn + 1];

void eG()
{
    cin >> n >> m;
    int u, v;
    REP(i, 1, n)
    {
        cin >> u >> v;
        a[-u].push_back(v);
        a[-v].push_back(u);
    }
}

void tarzan(int u)
{
    st.pb(u);
    low[u] = num[u] = ++t;
    for (int i = 0; i < a[u].size(); ++i)
    {
        int v = a[u][i];
        if (num[v])
            low[u] = min(low[u], num[v]);
        else
        {
            tarzan(v);
            low[u] = min(low[u], low[v]);
            if (W[v] == -1) W[u] = -1; // false
        }
    }

    if (low[u] == num[u])
    {
        if (W[u] == 0)
        {
            W[u] = 1; // true
            W[-u] = -1; //false
        }
        int v;
        do
        {
            v = st.back();
            st.pop_back();
            W[v] = W[u]; // trong cùng 1 SCC các đỉnh có cùng giá trị
            if (W[v] == W[-v]) {cout << "NO"; exit(0);}
            if (W[u] == 1) W[-v] = -1;
            num[v] = 1e9;
        } while (v != u);
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    eG();
    REP(i, 1, m) tarzan(i);
    REP(i, -m, -1) tarzan(i);
    cout << "YES\n"; int res = 0;
    REP(i, 1, m) if (W[i] == 1) ++res; cout << res << endl;
    REP(i, 1, m) if (W[i] == 1) cout << i << ' ';
}
