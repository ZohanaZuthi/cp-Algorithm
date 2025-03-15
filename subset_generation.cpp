#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<bits/stdc++.h>
#define f(a,n,i) for(int i=a;i<n;i+=1)
using namespace std;
const int N=1e5+10;
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
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


vector<vector<int>>subsets;

void generate(vector<int>&subset,int i,vector<int>&num)
{
    if(i==num.size())
    subsets.push_back(subset);
    generate(subset,i+1,num);
    subset.push_back(num[i]);
    generate(subset,i+1,num);
    subset.pop_back();
}
