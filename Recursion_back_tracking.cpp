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
set<vector<int>> comb;
vector<bool> used;
// https://codeforces.com/gym/105689/problem/B
void func(vector<int> &v, vector<int> temp)
{
    if (temp.size() == v.size())
    { // Store only full-length permutations
        comb.insert(temp);
        return;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if ((temp.empty() && v[i] == 0) || used[i]) // Skip leading 0 and used elements
            continue;

        used[i] = true;
        temp.push_back(v[i]);
        func(v, temp);
        temp.pop_back();
        used[i] = false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    used.resize(n, false);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    func(v, {});

    int ans = 0;
    for (auto &x : comb)
    {
        int sum = 0, count = 1;
        for (int i = x.size() - 1; i >= 0; i--)
        {
            // cout << x[i] << " ";
            sum += x[i] * count;
            count *= 10;
        }
        // cout << sum << endl;
        if (abs(2025 - sum) % 12 == 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
