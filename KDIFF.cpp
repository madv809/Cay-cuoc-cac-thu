#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

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

const int mxn = 2e6 + 5;

LL f[mxn], a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    LL n, k; scanf("%lli%lli", &n, &k);
    REP(i, 1, n) scanf("%lli", &a[i]);
    f[1] = 1; int mi = 1, mx = 1; LL res = 0;
    deque<int> smi, smx; smi.push_back(1); smx.push_back(1);
    REP(i, 2, n)
    {
        while (smi.size() && a[smi.back()] > a[i]) smi.pop_back(); smi.push_back(i);
        while (smx.size() && a[smx.back()] < a[i]) smx.pop_back();smx.push_back(i);

        while (a[i] - a[smi.front()] > k) {mi = smi.front() + 1; smi.pop_front();}
        while (a[smx.front()] - a[i] > k) {mx = smx.front() + 1; smx.pop_front();}
        f[i] = (LL)i - max(mi, mx) + 1LL;
        res = max(res, f[i] + f[i - f[i]]);
        f[i] = max(f[i], f[i-1]);
    }
    cout << res;
}
