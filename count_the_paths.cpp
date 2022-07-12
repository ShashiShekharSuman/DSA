#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dfs(int i, int d, vector<vector<int>> &adj)
    {
        if (i == d)
            return 1;
        int count = 0;
        for (auto j : adj[i])
            count += dfs(j, d, adj);
        return count;
    }

public:
    /*
    Given a directed acyclic graph(DAG) with n nodes labeled from 0 to n-1. Given edges, s and d ,count the number of ways to reach from s to d.There is a directed Edge from vertex edges[i][0] to the vertex edges[i][1].
    */
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        // Code here
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge : edges)
            adj[edge[0]].push_back(edge[1]);
        return dfs(s, d, adj);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, s, d;
        cin >> n >> m >> s >> d;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        int ans = obj.possible_paths(edges, n, s, d);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends