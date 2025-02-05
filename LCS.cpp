#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#define f(a, n, i) for (int i = a; i < n; i += 1)
using namespace std;
const int N = 1e5 + 10;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define el endl

#define pb push_back
#define ff first
#define ss second
typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const int INF = 1e9;
const ll LLINF = 1e18;
const int MOD = 1e9 + 7;

int main()
{

    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    string res;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
        }
    }
    // backtracking
    int x = n, y = m;
    while (x != 0 && y != 0)
    {
        if (arr[x][y] == arr[x - 1][y])
            x--;
        else if (arr[x][y] == arr[x][y - 1])
            y--;
        else
            res = str2[y - 1] + res;
    }
    cout << res << endl;

    return 0;
}