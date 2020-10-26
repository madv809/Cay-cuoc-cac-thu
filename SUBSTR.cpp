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
string a, b;
int f[1000001], res[1000001], c;

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    getline(cin, a);
    getline(cin>>ws, b);
    f[0] = -1;
    for (int i = 1; i < b.length(); ++i)
    {
        int j = f[i - 1];
        while (1)
        {
            if (b[j + 1] == b[i])
            {
                f[i] = j + 1;
                break;
            }
            else if (j != -1) j = f[j];
            else
            {
                f[i] = -1;
                break;
            }
        }
    }

    int i = 0, j = -1;
    while (1)
    {
        if (i == a.length()) break;
        if (a[i] == b[j + 1])
        {
            ++i; ++j;
            if (j == b.length() - 1)
            {
                res[++c] = i - b.length();
                j = f[j];
            }
        }
        else if (j != -1) j = f[j];
        else ++i;
    }

    FOR(i, 1, c) printf("%d ", res[i] + 1);
}
