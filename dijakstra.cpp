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

vector<pii>g[N];


void djkastra(ll source)
{   vector<ll>vis(N,0);
    vector<ll>dist(N,INF);
    // you can also use priority queue
    set<pii>st;
    dist[source]=0;
    
    
    while(st.size()>0)
    { 
       auto node=*st.begin();
       int v=node.second;
       int dis=node.first;
       st.erase(st.begin());
       if(vis[v]) continue;

       vis[v]=1;

       for(auto child:g[v])
       {
        int child_v=child.first;
        int wt=child.second;
        if(dist[v]+wt<dist[child_v])
        dist[child_v]=dist[v]+wt;
        st.insert({dist[child_v],child_v});
       }
      
    }

}



int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});

    }
    return 0;
}
