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

// segment tree is advance data structure
// it is mainly used for O(n) of queries
// it is a divide and conquer algorithm

struct segmenttree
{
    // building a segment tree
    int n;
    vector<int> st;
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    void build(int start, int end, int node, vector<int> &v)
    {
        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }

    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
        {
            return st[node];
        }
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return q1 + q2;
    }

    void update(int start, int ending, int node, int index, int value)
    {

        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {

            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {

            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];

        return;
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y)
    {
        update(0, n - 1, 0, x, y);
    }

} tree[26];

int main(int argc, char const *argv[])
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    // cout << v.size();

    segmenttree tree;

    tree.init(v.size());

    tree.build(v);

    cout << tree.query(0, 4) << '\n';

    tree.update(4, 10);

    cout << tree.query(2, 6) << '\n';

    tree.update(2, 20);

    cout << tree.query(0, 4) << '\n';

    return 0;
}
