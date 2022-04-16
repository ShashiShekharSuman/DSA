#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int start, vector<int> adj[], vector<bool> &visited, vector<bool> &vis)
    {

        visited[start] = true;
        vis[start] = true;
        for (auto i : adj[start])
        {
            if (!vis[i])
            {
                if (dfs(i, adj, visited, vis))
                    return true;
            }
            else if (visited[i])
                return true;
        }
        visited[start] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false), vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && dfs(i, adj, visited, vis))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
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