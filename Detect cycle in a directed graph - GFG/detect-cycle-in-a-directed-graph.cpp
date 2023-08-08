//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool detect(int node,vector<int>adj[],vector<int>&vis)
    {
        vis[node]=2;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
            {
                if(detect(it,adj,vis))
                return true;
            }
            else if(vis[it]==2) return true;
        }
        vis[node]=1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(detect(i,adj,vis))
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends