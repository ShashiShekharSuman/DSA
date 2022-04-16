#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void tarjons(int i, const vector<int> adj[], int &t, int &scc, stack<int> &s,
                 vector<int> &id, vector<int> &low, vector<bool> &visited)
    {

        s.push(i);
        visited[i] = true;
        low[i] = id[i] = t++;
        for (auto j : adj[i])
        {
            if (id[j] == -1)
            {
                tarjons(j, adj, t, scc, s, id, low, visited);
                low[i] = min(low[i], low[j]);
            }
            else if (visited[j])
                low[i] = min(low[i], id[j]);
        }
        if (low[i] == id[i])
        {
            scc++;
            while (!s.empty())
            {
                visited[s.top()] = false;
                if (s.top() == i)
                {
                    s.pop();
                    break;
                }
                s.pop();
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // tarjons Algo
        int scc = 0, t = 0;
        stack<int> s;
        vector<bool> visited(V, false);
        vector<int> id(V, -1), low(V);
        for (int i = 0; i < V; i++)
            if (id[i] == -1)
                tarjons(i, adj, t, scc, s, id, low, visited);
        return scc;
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