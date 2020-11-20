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
#define ULL unsigned long long

using namespace std;

int a[33], n, k;
long C[33][33];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    REP(i, 1, 32) C[1][i] = i;
    REP(j, 2, 32) REP(i, 1, 32) C[j][i] = C[j - 1][i - 1] + C[j][i - 1];
    REP(i, 0, 32) C[0][i] = 1;
    int x, cz;
    long res;
    while ((cin >> n >> k))
    {
        if (n == 0 && k == 1) {printf("1\n"); continue;}
        if (k < 0) {printf("0\n"); continue;}
        x = cz = 0; res = 0;
        while (n)
        {
            a[++x] = n&1;
            n >>= 1;
        }
        if (k > x) {printf("0\n"); continue;}
        for (int i = x - 2; i >= k; --i) res += C[k][i];

        for (int i = x - 1; i >= 1; --i)
        {
            if (a[i]){ if (k - cz > 0) res += C[k - cz - 1][i - 1];}
            else ++cz;
        }
        if (k == 1) ++res;
        if (cz == k) ++res;
        cout << res << endl;
    }
}
