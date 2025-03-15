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

int a[N], seg[N];
void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = a[low];
    }
    int mid = (low + high) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, low, mid);
    seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
int query(int ind, int low, int high, int l, int r)
{
    // completely lies
    if (low >= l && high <= r)
    {
        return seg[ind];
    }
    // It doesn't lies
    if (high < l || low > r)
        return INT_MIN;
    // overlaps
    int mid = (low + high) / 2;
    int left = query(2 * ind + 1, low, mid, l, r);
    int right = query(2 * ind + 2, mid + 1, high, l, r);
    return max(left, right);
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}
