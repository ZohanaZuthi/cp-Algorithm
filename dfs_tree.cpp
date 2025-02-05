#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];  // Adjacency list for the tree
int depth[N], height[N],even_count[N],sum[N];

void dfs(int vertex, int par = 0) {
    // Iterate over all children of the current vertex
    sum[vertex]+=vertex ;
    
    // or value
    if(vertex%2==0) even_count[vertex]++;
    for (int child : g[vertex]) {

        if (child == par) continue;  // Skip the parent
        
        depth[child] = depth[vertex] + 1;  // Update depth of the child
        
        dfs(child, vertex);  // Recursively call DFS for the child
        
        height[vertex] = max(height[vertex], height[child] + 1);  // Update height of the current vertex
        sum[vertex]+=sum[child];
        even_count[vertex]+=even_count[child];
        
    
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
    // sum of sub tree an even number vertex value
    // Output the depth and height of each vertex
    for (int i = 1; i <= n; i++) {
        cout << depth[i] << " " << height[i]<<" "<<sum[i]<<" "<<even_count[i]<< endl;
    } 
   

    

    return 0;
}