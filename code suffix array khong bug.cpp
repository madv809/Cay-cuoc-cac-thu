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
#include <bitset>
#include <unordered_map>

#define LL long long
#define ULL unsigned long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
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
#define ef else if
#define lb lower_bound
#define even "even"
#define odd "odd"

using namespace std;
const int mxn = 1e6 + 5;
const int MOD = 234567899;
const int BASE = 10000;
const int INF = 1e9 + 123;
int SA[mxn], RA[mxn], tmpRA[mxn], tmpSA[mxn], c[mxn], lcp[mxn], n, k;
string s;

void counting_sort(const int &k, int r)
{
    r = max(300, r);
    REP(i, 0, r) c[i] = 0;
    FOR(i, 0, n) ++c[(i + k < n) ? RA[i + k] : 0];
    REP(i, 1, r) c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; --i)
        tmpSA[--c[(SA[i] + k < n) ? RA[SA[i] + k] : 0]] = SA[i];
    FOR(i, 0, n) SA[i] = tmpSA[i];
}

void suff()
{
    FOR(i, 0, n) SA[i] = i;;
    FOR(i, 0, n) RA[i] = s[i];

    int r = n;
    for (int k = 1; k < n; k <<= 1)
    {
        counting_sort(k, r); counting_sort(0, r);
        tmpRA[SA[0]] = r = 0;

        FOR(i, 1, n)
            tmpRA[SA[i]] = (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;

        FOR(i, 0, n) RA[i] = tmpRA[i];
        if (r == n - 1) return;
    }
}

void kasai()
{
    FOR(i, 0, n) RA[SA[i]] = i;
    int k = 0;

    FOR(i, 0, n - 1)
    {
        int j = SA[RA[i] - 1];
        while (s[i + k] == s[j + k]) ++k;
        lcp[RA[i]] = k;
        if (--k < 0) k = 0;
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
}













