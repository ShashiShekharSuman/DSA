// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int dfs(int i, int target, vector<vector<vector<int>>> &adj, vector<int> &distance)
    {
        if (i == target)
            return distance[i] = 0;

        for (auto j : adj[i])
        {
            if (distance[j[0]] == INT_MIN)
                dfs(j[0], target, adj, distance);
            distance[i] = max(distance[i], (distance[j[0]] == INT_MIN + 1 ? INT_MIN + 1 : distance[j[0]] + j[1]));
        }

        if (distance[i] == INT_MIN)
            distance[i]++;
        return distance[i];
    }

public:
    /*
    Given a Weighted Directed Acyclic Graph (DAG) and a source vertex s in it, find the longest distances from s to all other vertices in the given graph.
    Note: return INT_MIN in case path does not exist.
    */
    vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
    {
        // code here
        vector<vector<vector<int>>> adj(v);
        vector<int> distance(v, INT_MIN);

        for (auto edge : edges)
            adj[edge[1]].push_back({edge[0], edge[2]});

        for (int i = 0; i < v; i++)
            if (distance[i] == INT_MIN)
                dfs(i, src, adj, distance);

        for (int i = 0; i < v; i++)
            if (distance[i] == INT_MIN + 1)
                distance[i]--;

        return distance;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int v, e;
        cin >> v >> e;

        int src;
        cin >> src;
        vector<vector<int>> edges(e, vector<int>(3));
        for (auto &j : edges)
            cin >> j[0] >> j[1] >> j[2];

        Solution s;
        vector<int> ans = s.maximumDistance(edges, v, e, src);
        for (auto j : ans)
        {
            if (j == INT_MIN)
                cout << "INF ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;

} // } Driver Code Ends