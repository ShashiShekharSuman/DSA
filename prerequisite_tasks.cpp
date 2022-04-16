#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int start, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[start] = 1;
        for (auto i : adj[start])
        {
            if (visited[i] == 1)
                return true;
            if (visited[i] == -1 && dfs(i, adj, visited))
                return true;
        }
        visited[start] = 0;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        vector<int> visited(N, -1);
        vector<vector<int>> adj(N);
        for (auto i : prerequisites)
            adj[i.second].push_back(i.first);
        for (int i = 0; i < N; i++)
        {
            if (visited[i] == -1 && dfs(i, adj, visited))
                return false;
        }
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
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends