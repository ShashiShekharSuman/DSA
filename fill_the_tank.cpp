#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    long long dfs(int start, vector<vector<int>> &adj, vector<bool> &visited, int *cap)
    {
        visited[start] = true;
        long long water = cap[start], count = 0, overflow = 0;
        for (auto i : adj[start])
        {
            if (!visited[i])
            {
                long long temp = dfs(i, adj, visited, cap);
                if (temp == -1)
                    return -1;
                overflow = max(overflow, temp);
                count++;
            }
        }
        return (water + count * overflow) > 1e18 ? -1 : water + count * overflow;
    }

public:
    long long minimum_amount(vector<vector<int>> &Edges, int num, int start, int *cap)
    {
        // Code here
        vector<vector<int>> adj(num, vector<int>());
        vector<bool> visited(num, false);
        for (auto edge : Edges)
        {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        return dfs(start - 1, adj, visited, cap);
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, start;
        cin >> num >> start;
        int cap[num];
        for (int i = 0; i < num; i++)
            cin >> cap[i];

        vector<vector<int>> Edges(num - 1);
        for (int i = 0; i < num - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            Edges[i].push_back(u);
            Edges[i].push_back(v);
        }

        Solution obj;
        long long ans = obj.minimum_amount(Edges, num, start, cap);
        cout << ans << endl;
    }

    return 0;
} // } Driver Code Ends