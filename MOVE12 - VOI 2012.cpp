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
const int INF = 1e9;
const LL BASE = 311;
const LL MOD = 1e9 + 7;
pii a[mxn], l[mxn];
int n;
 
bool can (int x)
{
    REP(i, 1, n)
    {
        int k = (int)(x/a[i].Y);
        l[i].X = a[i].X - k;
        l[i].Y = a[i].X + k;
    }
    sort(l + 1, l + n + 1);
    int nn = 1;
    priority_queue<int, vector<int>, greater<int>> h;
 
    REP(i, 1, n)
    {
         while (nn <= n && l[nn].X <= i)
            h.push(l[nn++].Y);
         if (!h.size()) return 0;
         if (h.top() < i) return 0;
         h.pop();
    }
    return 1;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    REP(i, 1, n) cin >> a[i].X >> a[i].Y;
    int l = 0, r = n*10000;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (can(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
}
 
