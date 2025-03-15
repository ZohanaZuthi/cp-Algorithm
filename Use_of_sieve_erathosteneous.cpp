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

vector<int> sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> v;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
            v.push_back(i);
    }
    return v;
}

int main()
{
    int n = 50, count = 0, queries = 0;
    vector<int> v = sieve(n);
    bool bol = false;
    int mul = 1;

    for (int i = 0; i < v.size() && queries < 20; i++)
    {
        if (mul * v[i] <= 100)
        {
            cout << v[i] << endl;
            cout.flush();
            queries++;
            string in;
            cin >> in;
            if (in == "yes")
            {
                mul *= v[i];
                count++;
            }
            if (count == 2)
            {
                bol = true;
                break;
            }
        }
    }

    if (!bol && mul > 1 && mul * mul <= 100 && queries < 20)
    {
        cout << mul * mul << endl;
        cout.flush();
        queries++;
        string in;
        cin >> in;
        if (in == "yes")
            bol = true;
    }

    if (bol)
        cout << "composite" << endl;
    else
        cout << "prime" << endl;

    return 0;
}
