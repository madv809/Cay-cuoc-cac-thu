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
 
#define LL unsigned long long
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
const LL BASE = 95;
const LL MOD = 1e9 + 7;
int n; string s;
LL Hasht[mxn], Hashp[mxn], powB[mxn];
 
LL get_Hashp (int i, int j)
{
    return (Hashp[j] - Hashp[i - 1]*powB[j - i + 1]);
}
 
LL get_Hasht (int i, int j)
{
    return (Hasht[i] - Hasht[j + 1]*powB[j - i + 1]);
}
 
bool yes (int x)
{
    for (int i = 1; i <= n - x + 1; ++i)
    {
        LL x1 = 1, x2 = 1;
        if (get_Hashp(i, i + x - 1) == get_Hasht(i, i + x - 1)) return 1;
    }
    return 0;
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    //freopen("hshoe.in", "r", stdin);
    //freopen("hshoe.out", "w", stdout);
    cin >> n; cin >> s; s = '1' + s;
    REP(i, 1, n) Hashp[i] = Hashp[i - 1]*BASE + int(s[i] - 'a' + 1);
    for (int i = n; i >= 1; --i) Hasht[i] = Hasht[i + 1]*BASE + int(s[i] - 'a' + 1);
    powB[0] = 1;
    REP(i, 1, n) powB[i] = powB[i - 1]*BASE;
 
    int l = 1, r = n - (n%2 == 0);
    while (l < r)
    {
        int mid = (l + r) >> 1; if (mid % 2 == 0) ++mid;
        if (yes(mid)) l = mid;
        else r = mid - 2;
    }
 
    int res = l;
    l = 0, r = n - (n&1);
    while (l < r)
    {
        int mid = (l + r) >> 1; if (mid&1) ++mid;
        if (yes(mid)) l = mid;
        else r = mid - 2;
    }
    res = max(res, l);
    cout << res << endl;
}
