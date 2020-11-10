#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define ii pair<int, int>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

using namespace std;
int n;
LL a[800001], b[800001], c[800001], res;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= 2*n; ++i) scanf("%lli%lli", &a[i], &b[i]);

    for (int i = 1; i <= 2*n; ++i) res += b[i];
    for (int i = 1; i <= 2*n; ++i) c[i] = a[i]-b[i];
    sort(c + 1, c + 2*n + 1);
    for (int i = 1; i <= n; ++i) res+= c[i];
    printf("%lli", res);
}
