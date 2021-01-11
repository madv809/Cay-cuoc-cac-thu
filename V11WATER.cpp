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
LL h[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n; int mx = 1;
    REP(i, 1, n) {scanf("%lli", &h[i]); if (h[mx] < h[i]) mx = i;}

    LL h_mx = h[1], res = 0;
    FOR(i, 1, mx)
    {
        if (h[i] > h_mx) h_mx = h[i];
        else res += h_mx - h[i];
    }
    h_mx = h[n];
    for (int i = n; i > mx; --i)
    {
        if (h[i] > h_mx) h_mx = h[i];
        else res += h_mx - h[i];
    }
    cout << res;
}
