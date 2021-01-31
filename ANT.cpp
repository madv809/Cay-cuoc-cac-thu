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
const int mxn = 1e5 + 5;
const LL INF = 1e18;
int d[mxn], a[mxn], n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    /*p  = m*k + r;
    p2 = (m - 1)*k + r + n;  //do 0 < r < m nên ta phải trừ đi 1 trong code ở dưới khi chia cho (m - 1)
    p2 + k - n = m*k + r = p;*/
    LL m, n;
    cin >> n >> m;
    LL p = m*n;
    while (p > n) p = p + (p - n - 1)/(m - 1) - n;
    cout << p;
}
