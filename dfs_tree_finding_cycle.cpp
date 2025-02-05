#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];  // Adjacency list for the tree
int vis[N];

bool dfs(int vertex, int par) {
    // Iterate over all children of the current vertex
    vis[vertex]=true;
    // as though one of the child of a cycle might return false and othe return true
    // so if we have one true we will return true;
    bool isLoopExists=false;   
    // when finding cycle we want to exclude the vertex from where the vertex came from
    // so we must keep track of the vertex from where the current edge came from
    for (int child : g[vertex]) {
        if(vis[child]&&child==par) continue;
        if(vis[child]) return true;
        
        isLoopExists|=dfs(child,vertex);
        
    
    }
    return isLoopExists;
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

    bool isLoopExists=false;
    
   for(int i=1;i<=n;i++)
    {
      if(vis[i]) continue;
      if(dfs(i,0)){
        isLoopExists=true;
        break;
      }

    }
    cout<<isLoopExists<<endl;
    return 0;
}