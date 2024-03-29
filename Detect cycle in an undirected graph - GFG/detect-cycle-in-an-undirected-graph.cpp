//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfsdetect(int u, int p, vector<int> adj[], bool vis[])
    {
        vis[u] = true;
        for(auto v: adj[u])
        {
            if(!vis[v])
            {
                if(dfsdetect(v,u,adj,vis) == true)
                {
                    return true;
                }
            }
            else if(v != p)
            {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool vis[V]={false};
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
                if(dfsdetect(i,-1, adj, vis) == true)
                    return true;
        }
        return false;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends