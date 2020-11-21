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

using namespace std;
LL C[33][33], a[33], x, y, k, b;

LL ff (LL n)
{
    int x = 0, cz = 0;
    LL res = 0; bool ok = 0;
    while (n)
    {
        a[++x] = n%b;
        n /= b;
    }

    cz = 1;
    for (int i = x - 1; i >= 1; --i)
    {
        if (a[i])
        {
            if (k - cz >= 0) res += C[k - cz][i - 1];
            if (a[i] > 1 && k - cz > 0) {res += C[k - cz - 1][i - 1]; break;}
            ++cz;
        }
    }
    if (a[x] > 1) res = C[k - 1][x - 1];

    for (int i = x - 2; i >= k - 1; --i) res += C[k - 1][i];

    if (cz == k && a[x] == 1) ++res;
    return res;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> x >> y >> k >> b;
    REP(i, 0, 30) C[0][i] = 1;
    REP(i, 1, 30) REP(j, 1, i) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    cout << (ff(y) - ff(x - 1));
}
