#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];  // Adjacency list for the tree
int vis[N];
// storing the connected componenet
vector<int>current_cc;
vector<vector<int>>cc;
void dfs(int vertex, int par = 0) {
    // Iterate over all children of the current vertex
    vis[vertex]=true;   
    current_cc.push_back(vertex);
    for (int child : g[vertex]) {
        if(vis[child])continue;
        
        dfs(child);
        
    
    }
}

int main() {
    int n;
    cin >> n;
    
    // Reading edges and building the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // Start DFS from vertex 1, assuming 1 as the root
    dfs(1);
  
    // count of connected component
    int ct=0;
    for(int i=1;i<=n;i++)
    {
      if(vis[i]) continue;
      current_cc.clear();
      dfs(i);
      cc.push_back(current_cc);
      ct++;

    }


    return 0;
}