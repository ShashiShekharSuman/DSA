#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    bool dfs(int i, int path, int k, vector<vector<vector<int>>> &adj, vector<bool> &visited)
    {
        visited[i] = true;
        if (path >= k)
            return true;
        for (auto j : adj[i])
        {
            if (visited[j[0]])
                continue;
            if (dfs(j[0], path + j[1], k, adj, visited))
                return true;
        }
        visited[i] = false;
        return false;
    }

public:
    /*
    Given a graph, a source vertex in the graph, and a number k, find if there is a simple path, of path length greater than or equal to k,(without any cycle) starting from a given source and ending at any other vertex.
    Source vertex should always be  0.
    */
    bool pathMoreThanK(int V, int E, int k, int *a)
    {
        //  Code Here
        vector<vector<vector<int>>> adj(V);
        vector<bool> visited(V, false);
        for (int i = 0; i < 3 * E; i += 3)
        {
            adj[a[i]].push_back({a[i + 1], a[i + 2]});
            adj[a[i + 1]].push_back({a[i], a[i + 2]});
        }
        return dfs(0, 0, k, adj, visited);
    }
};

// { Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3 * E + 1];
        for (int i = 0; i < 3 * E; i++)
        {
            cin >> a[i];
        }

        Solution obj;
        if (obj.pathMoreThanK(V, E, K, a))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
} // } Driver Code Ends