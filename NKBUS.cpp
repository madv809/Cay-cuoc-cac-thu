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
vector<int> a;
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m, sum = 0; cin >> n >> m;
    REP(i, 1, n)
    {
        int  t, k;
        cin >> t >> k;
        REP(j, 1, k)
        {
            int x;
            cin >> x;
            a.push_back(x - sum);
        }
        sum += t;
    }
 
    int res = sum;
    sort(a.begin(), a.end());
    if (a.size() <= m) res += (a.back() > 0)?(a.back()):0;
    else res += a[m - 1];
    cout << res << endl;
    //for (int x : a) cout << x <<' ';
}
