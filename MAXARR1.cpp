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
const LL BASE = 311;
pLL tt[mxn], a[mxn];
LL rose[mxn];
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int t; cin >> t;
    REP(i, 1, t) {scanf("%lli", &tt[i].X); tt[i].Y = i;}
    sort(tt + 1, tt + t + 1);
    a[0].X = 0;
    a[1].X = 1;
    REP(i, 2, 1e5)
    {
        if (i&1) a[i].X = a[i/2].X + a[i/2 + 1].X;
        else a[i].X = a[i/2].X;
        a[i].Y = i;
    }
    sort(a + 1, a + 100000 + 1);
    int r = 1e5;
    for (int i = t; i >= 1; --i)
    {
        while (a[r].Y > tt[i].X) --r;
        rose[tt[i].Y] = a[r].X;
    }
    REP(i, 1, t) cout << rose[i] << endl;
}
