#define LL long long
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>

using namespace std;
struct point
{
    double x, y;
} a[100001];
double mindist = 1e20;
int n;

double dist (const point &a, const point &b)
{
    return (sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

bool cmpx (const point &a, const point &b)
{
    return (a.x < b.x);
}

bool cmpy (const point &a, const point &b)
{
    return (a.y < b.y);
}

void upd(const point &a, const point &b)
{
    double x = dist(a, b);
    if (x < mindist) mindist = x;
}

void findd (int l, int r)
{
    if (r <= l) return;
    if (r == l + 1)
    {
        upd(a[l], a[r]);
        if (!cmpy(a[l], a[r]))
            swap(a[l], a[r]);
        return;
    }
    static point t[100001];
    int mid = (l + r) >> 1;
    double midx = a[mid].x;
    findd(l, mid);
    findd(mid + 1, r);
    merge(a + l, a + mid + 1, a + mid + 1, a + r + 1, t, cmpy);
    copy(t, t + r - l + 1, a + l);
    int c = 0;
    for (int i = l; i <= r; ++i) if (abs(a[i].x - midx) < mindist)
    {
        for (int j = c; j >= 1 && a[i].y - t[j].y < mindist; --j) upd(a[i], t[j]);
        t[++c] = a[i];
    }
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + n + 1, cmpx);
    findd(1, n);
    cout << setprecision(3) << fixed << mindist;
}
