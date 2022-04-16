#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int start, int color, vector<int> adj[], vector<int> &visited)
    {
        visited[start] = color;
        for (auto i : adj[start])
        {
            if (visited[start] == visited[i])
                return false;
            if (visited[i] == -1 && !dfs(i, 1 - color, adj, visited))
                return false;
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, -1);
        for (int i = 0; i < V; i++)
            if (visited[i] == -1 && !dfs(i, 0, adj, visited))
                return false;
        return true;
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
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends