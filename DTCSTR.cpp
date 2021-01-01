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
 
const int mxn = 1e6 + 5;
const int INF = 1e9;
const LL BASE = 311;
int z[mxn], f[mxn], g[mxn], kk[mxn], n, max_dis;
set<int, greater<int>> s_length;
string s; bool tf[mxn];
struct node
{
    int l, r;
} gr[mxn];
 
void Z ()
{
    cin >> s; n = s.length();
    int l, r; l = r = 0;
    for (int i = 1; i < n; ++i)
    {
        int k = i - l;
        if (z[k] < r - i + 1) z[i] = z[k];
        else
        {
            l = i; r = max(r, i);
            while (s[r - l] == s[r]) ++r;
            z[i] = r - l; --r;
        }
    }
}
 
void add (int x)
{
    int l, r; l = r = x;
    tf[x] = 1;
    gr[x].l = gr[x].r = x;
    if (tf[x - 1])
    {
        gr[x].l = gr[x - 1].l;
        gr[gr[x].l].r = x;
    }
 
    if (tf[x + 1])
    {
        gr[gr[x].l].r = gr[x + 1].r;
        gr[gr[x + 1].r].l = gr[x].l;
    }
    int k = gr[x].l;
    max_dis = max(max_dis, gr[k].r - gr[k].l + 1);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    Z();
    z[0] = n;
    memset(g, -1, sizeof(g));
    FOR(i, 0, n) if (g[z[i]] == -1) g[z[i]] = i;
    for (int i = n - 1; i >= 0; --i){f[i] = kk[z[i]];kk[z[i]] = i;}
 
    int res = n;
    FOR(i, 0, n)
    {
        if (i != 0 && max_dis <= i - 1) {res = i; break;}
        int x = g[i];
        if (x == -1) continue;
        do
        {
            add(x);
            x = f[x];
        } while (x != 0);
    }
    cout << res << endl;
    /*FOR(i, 0, n) cout << s[i] << ' '; cout << endl;
    FOR(i, 0, n) cout << z[i] << ' '; cout << endl;
    cout << gr[1].l << ' ' << gr[1].r;*/
}
