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
struct no_more
{
    int XX, YY, ZZ;
};
 
bool cmp(no_more A, no_more B)
{
    return (A.XX < B.XX);
}
 
no_more a[mxn];
int b[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) cin >> a[i].XX;
    REP(i, 1, n) cin >> a[i].YY;
    REP(i, 1, n) a[i].ZZ = i;
    sort(a + 1, a + n + 1, cmp);
    REP(i, 1, n) b[i] = a[i].ZZ;
    LL res = a[1].YY;
    priority_queue<pii> h;
    vector<int> cres;
    for (int i = 3; i < n; i += 2)
    {
        h.push({a[i - 1].YY, i - 1}); h.push({a[i].YY, i});
        res += h.top().X;
        cres.pb(h.top().Y);
        h.pop();
    }
    cout << res << endl;
    cres.pb(1);
    sort(cres.begin(), cres.end());
    priority_queue<int> h2;
    while (h.size())
    {
        h2.push(h.top().Y);
        h.pop();
    }
    h2.push(n);
    for (int i = cres.size() - 1; i >= 0; --i)
    {
        cout << b[cres[i]] << ' ' << b[h2.top()] << endl;
        h2.pop();
    }
}
 
