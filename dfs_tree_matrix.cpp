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

// flood fill problem
// https://leetcode.com/problems/flood-fill/description/

vector<int>g[N];

void dfs(int i,int j,int initialColor,int newColor,vector<vector<int>>&image)
{   int n=image.size();
    int m=image[0].size();
    if(i<0||j<0) return;
    if(i>=n||j>=m) return;

    if(image[i][j]!=initialColor) return;
    image[i][j]=newColor;

    dfs(i-1,j,initialColor,newColor,image);
    dfs(i+1,j,initialColor,newColor,image);
    dfs(i,j-1,initialColor,newColor,image);
    dfs(i,j+1,initialColor,newColor,image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
{

    int initialColor=image[sr][sc];
    int newColor=color;
    if(initialColor!=newColor)
        dfs(sr,sc,initialColor,newColor,image);
    return image;
        
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    // Reading edges and building the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    return 0;
}
