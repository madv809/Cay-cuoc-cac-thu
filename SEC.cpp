
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
const LL MOD = 1e9+7;
struct node
{
    node *child[2]; int n, m;
    node ()
    {
        child[0] = NULL; child[1] = NULL;
        n = m = 0;
    }
};
node *root = new node();

const int mxn = 5e5 + 5;
int a[mxn];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m; cin >> n >> m; int x, k;
    REP(i, 1, n)
    {
        scanf("%d", &x);
        node *p = root;
        FOR(j, 0, x)
        {
            scanf("%d", &k);
            if (p->child[k] == NULL) p->child[k] = new node();
            p = p->child[k]; ++p->m;
        }
        --p->m; ++p->n;
    }

    REP(i, 1, m)
    {
        node *p = root; int res = 0;
        scanf("%d", &x); bool ok = 1;
        FOR(j, 0, x)
        {
            scanf("%d", &k);
            if (!ok) continue;
            if (p->child[k] == NULL)
            {
                ok = 0;
                continue;
            }
            p = p->child[k]; res += p->n;
        }
        if (ok) res += p->m;
        printf("%d\n", res);
    }
}
