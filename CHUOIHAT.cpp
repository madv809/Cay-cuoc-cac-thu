#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
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
int n;
string dp[252][502], sum[252][502];
string x;

string operator +(string a, string b)
{
    while (a.length() < b.length()) a = '0' + a;
    while (b.length() < a.length()) b = '0' + b;
    int tmp = 0;
    string res = "";
    for (int i = a.length() - 1; i >= 0; --i)
    {
        tmp = a[i] - '0' + b[i] - '0' + tmp;
        res = (char)((tmp%10) + 48) + res;
        tmp /= 10;
    }
    if (tmp != 0) res = (char)(tmp + 48) + res;
    return res;
}

string operator - (string a, string b)
{
    while (b.length() < a.length()) b = '0' + b;
    int tmp = 0;
    string res;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        tmp = a[i] - b[i] - tmp + 10;
        res = (char)(tmp%10 + 48) + res;
        tmp = 1 - tmp/10;
    }
    while (res[0] == '0') res.erase(0, 1);
    if (!res.length()) res = "0";
    return res;
}

bool operator < (string a, string b)
{
    if (a.length() != b.length()) return (a.length() < b.length());
    for (int i = 0; i < a.length(); ++i) if (a[i] != b[i]) return (a[i] < b[i]);
    return 0;
}

bool operator > (string a, string b)
{
    if (a.length() != b.length()) return (a.length() > b.length());
    for (int i = 0; i < a.length(); ++i) if (a[i] != b[i]) return (a[i] > b[i]);
    return 0;
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    int k = 1;
    cin >> x;
    for (int i = 2*n; i >= 1; --i)
    {
        dp[n][i] = "1";
        sum[n][i] = dp[n][i] + sum[n][i + 1];
    }

    for (int i = n - 1; i >= 1; --i)
    {
        for (int j = 2*i; j >= i; --j)
        {
            dp[i][j] = sum[i + 1][j + 1];
            sum[i][j] = dp[i][j] + sum[i][j + 1];
        }
    }

    REP(i, 1, n)
    {
        for (int j = k; j <= 2*i; ++j)
        {
            if (x > dp[i][j]) x = x - dp[i][j];
            else
            {
                printf("%d ", j);
                k = j + 1;
                break;
            }
        }
    }
}
