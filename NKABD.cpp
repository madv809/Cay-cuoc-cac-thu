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
LL l[mxn];
vector<LL> prime;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(i, 2, 1e5)
    {
        if (!l[i])
        {
            l[i] = i;
            prime.push_back(i);
        }
        LL k = 1e5/i;
        for (int j = 0; j < prime.size() && prime[j] <= l[i] && prime[j] <= k; ++j)
            l[prime[j]*i] = prime[j];
    }

    int a, b; cin >> a >> b;
    int res = 0;
    REP(i, a, b)
    {
        int x = i, kk = 0;
        vector<LL> r;
        while (x != 1)
        {
            if (kk != l[x]) r.push_back(l[x]);
            else (r.back() *= l[x]) += l[x];
            kk = l[x];
            x /= l[x];
        }
        LL k = 1;
        for (LL j : r) k *= (j + 1);
        if (k > 2*i) ++res;
    }
    cout << res;
}
