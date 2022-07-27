#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &visited)
    {
        visited[i] = true;
        for (int j = 0; j < adj.size(); j++)
            if (adj[i][j] == 1 && !visited[j])
                dfs(j, adj, visited);
    }

public:
    /*
    Given a graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

    Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.
    */
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        int provinces = 0;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
            if (!visited[i])
            {
                dfs(i, adj, visited);
                provinces++;
            }

        return provinces;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends