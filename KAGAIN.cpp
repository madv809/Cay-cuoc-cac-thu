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
#define ii pair<int, int>

using namespace std;
const int INF = 99999999;
int a[30001], l[30001], r[30001], t, n;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &t);
    a[0] = -INF;
    while (t--)
    {
        scanf("%d", &n);
        vector <int> sta; sta.push_back(0);
        REP(i, 1, n) scanf("%d", &a[i]);
        REP(i, 1, n)
        {
            while (sta.size() > 1 && a[i] <= a[sta.back()]) sta.pop_back();
            l[i] = sta.back() + 1;
            sta.push_back(i);
        }
        sta.clear(); sta.push_back(n+1); a[n+1] = INF;
        for (int i = n; i >= 1; --i)
        {
            while (sta.size() > 1 && a[i] <= a[sta.back()]) sta.pop_back();
            r[i] = sta.back() - 1;
            sta.push_back(i);
        }
        #define res(i) (a[i]*(r[i]-l[i]+1))
        int x = 0;
        REP(i, 1, n) if (res(i) > res(x)) x = i;
        printf("%d %d %d\n", res(x), l[x], r[x]);
    }
}
