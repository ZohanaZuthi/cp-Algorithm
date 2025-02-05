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
// level is important in bfs, as it gets confusing
// bfs implementation is related to queue
int vis[N];
int level[N];
vector<int>g[N];

void bfs(int source)
{   queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty())
    {
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child:g[cur_v])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }

        }

    }
    cout<<endl;

}


int main()
{
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
    int v1,v2;
    cin>>v1>>v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<level[i]<<endl;
    }
    return 0;
}