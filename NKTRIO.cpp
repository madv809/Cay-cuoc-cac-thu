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

const int mxn = 2e3 + 5;
const LL INF = 1e18;
const LL BASE = 311;
int a[mxn][mxn], r[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) REP(j, 1, n) scanf("%d", &a[i][j]);
    int k = 2;
    r[1] = 1; r[2] = 2;
    if (a[2][1]) swap(r[1], r[2]);
    REP(i, 3, n)
    {
        r[++k] = i;
        int j = 1;
        for ( ; j < i; ++j) if (a[r[k]][r[j]])
        {
            for (int x = j + 1; x < i; ++x) if (a[r[x]][r[k]])
            {
                cout << r[k] << ' ' << r[j] << ' ' << r[x];
                return 0;
            }
            break;
        }
        for (int x = i; x > j; --x) r[x] = r[x - 1];
        r[j] = i;
    }
    cout << "-1 -1 -1";
}
