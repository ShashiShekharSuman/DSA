#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

    void dfs(int start, const vector<int> adj[], vector<bool> &visited, stack<int> &s)
    {
        visited[start] = true;
        for (auto i : adj[start])
        {
            if (visited[i])
                continue;
            dfs(i, adj, visited, s);
        }
        s.push(start);
    }

    void reverseDfs(int start, const vector<vector<int>> &reverseAdj, vector<bool> &visited)
    {
        visited[start] = false;
        for (auto i : reverseAdj[start])
        {
            if (!visited[i])
                continue;
            reverseDfs(i, reverseAdj, visited);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {

        // code here
        vector<bool> visited(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, adj, visited, s);
        }

        vector<vector<int>> reverseAdj(V, vector<int>());
        for (int i = 0; i < V; i++)
            for (auto j : adj[i])
                reverseAdj[j].push_back(i);

        int count = 0;
        while (!s.empty())
        {
            if (visited[s.top()])
            {
                count++;
                reverseDfs(s.top(), reverseAdj, visited);
            }
            s.pop();
        }
        return count;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends