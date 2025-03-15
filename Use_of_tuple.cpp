#include <bits/stdc++.h>
using namespace std;

#define f(a, n, i) for (int i = a; i < n; i += 1)
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
// https://codeforces.com/contest/1846/problem/C
pair<int, int> func(vector<int> &v, int h)
{
    int sum = 0, solved = 0, penalty = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (sum + v[i] > h)
            break;
        sum += v[i];
        solved++;
        penalty += sum; // Correct penalty calculation
    }
    return {solved, penalty};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, h;
        cin >> n >> m >> h;
        vector<tuple<int, int, int>> v;

        for (int i = 0; i < n; i++)
        {
            vector<int> t(m);
            for (int j = 0; j < m; j++)
                cin >> t[j];

            sort(t.begin(), t.end()); // Sort to get optimal order

            int p, q;
            tie(p, q) = func(t, h); // Compute solved problems & penalty

            v.push_back({p, q, i});
        }

        // Sort based on problems solved (descending), penalty (ascending), index (ascending)
        sort(v.begin(), v.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
             {
                 if (get<0>(a) != get<0>(b))
                     return get<0>(a) > get<0>(b); // More problems solved first
                 if (get<1>(a) != get<1>(b))
                     return get<1>(a) < get<1>(b); // Lower penalty first
                 return get<2>(a) < get<2>(b);     // Maintain original order for equal values
             });

        // Find the ranking of Rudolph (participant 0)
        for (int i = 0; i < n; i++)
        {
            if (get<2>(v[i]) == 0) // Find Rudolph's position
            {
                cout << i + 1 << endl; // 1-based index
                break;
            }
        }
    }
    return 0;
}
