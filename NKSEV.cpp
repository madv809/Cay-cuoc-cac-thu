
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
const LL MOD = 1337377;
struct node
{
    node *child[26]; int n;
    node ()
    {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        n = 0;
    }
};
node *root = new node();

void add (const string &s)
{
    node* p = root;
    for (int i = s.length()-1; i >= 0; --i)
    {
        int nx = s[i] - 'a';
        if (p->child[nx] == NULL) p->child[nx] = new node();
        p = p->child[nx];
    }
    ++p->n;
}

const int mxn = 3e5 + 5;
LL ff[mxn]; LL *f = &ff[1];
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    string s; cin >> s;
    int n; cin >> n;
    REP(i, 1, n)
    {
        string tmp; cin >> tmp;
        add(tmp);
    }

    f[-1] = 1;
    for (int i = 0; i < s.length(); ++i)
    {
        node* p = root;
        for (int j = i; j >= 0; --j)
        {
            int nx = s[j] - 'a';
            if (p->child[nx] == NULL)break;
            p = p->child[nx];
            (f[i] += (p->n != 0)*f[j-1])%=MOD;
        }
    }
    cout << f[s.length()-1];
}
