// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void dfs(int start, vector<int> adj[], vector<bool> &visited)
    {
        visited[start] = true;
        for (auto i : adj[start])
            if (!visited[i])
                dfs(i, adj, visited);
    }

public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> start(26, 0), end(26, 0), adj[26];
        vector<bool> visited(26, false);
        for (int i = 0; i < A.size(); i++)
        {
            start[A[i][0] - 'a']++;
            end[A[i].back() - 'a']++;
            adj[A[i][0] - 'a'].push_back(A[i].back() - 'a');
        }
        for (int i = 0; i < 26; i++)
            if (start[i] != end[i])
                return 0;
        dfs(A[0][0] - 'a', adj, visited);
        for (int i = 0; i < 26; i++)
            if (start[i] && !visited[i])
                return 0;
        return 1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(N, A) << endl;
    }
    return 0;
} // } Driver Code Ends