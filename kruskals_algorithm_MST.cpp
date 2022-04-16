#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    class DisjointSet
    {
        int *rank, *parent, n;

    public:
        DisjointSet(int n)
        {
            rank = new int[n];
            parent = new int[n];
            this->n = n;
            makeSet();
        }

        void makeSet()
        {
            for (int i = 0; i < n; i++)
            {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        int find(int n)
        {
            if (parent[n] == n)
                return n;
            return parent[n] = find(parent[n]);
        }

        void Union(int a, int b)
        {
            int x = find(a),
                y = find(b);

            if (x == y)
                return;
            if (rank[x] < rank[y])
                swap(x, y);
            parent[x] = y;
            rank[y] += rank[x];
        }
    };

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
                edges.push_back({i, adj[i][j][0], adj[i][j][1]});
        }

        sort(
            edges.begin(),
            edges.end(),
            [](const vector<int> &a, const vector<int> &b)
            {
                return a[2] < b[2];
            });

        int minSpanningCost = 0;
        DisjointSet ds(V);
        for (auto i : edges)
        {
            int x = ds.find(i[0]),
                y = ds.find(i[1]);
            if (x == y)
                continue;
            ds.Union(i[0], i[1]);
            minSpanningCost += i[2];
        }
        return minSpanningCost;
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends