#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCyclic(int start, int prev, vector<int> adj[], vector<bool> &visited)
    {
        visited[start] = true;
        for (auto i : adj[start])
        {
            if (i != prev)
            {
                if (visited[i])
                    return true;
                if (isCyclic(i, start, adj, visited))
                    return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && isCyclic(i, -1, adj, visited))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
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
} // } Driver Code Ends