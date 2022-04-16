// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    class StateSpace
    {
        vector<vector<bool>> grid;

    public:
        vector<int> position;
        StateSpace(int n)
        {
            grid = vector<vector<bool>>(n, vector<bool>(n, false));
            position = vector<int>(n, 0);
        }

        bool isSafe(int i, int j, const int n)
        {
            if (i < 0 || i >= n || j < 0 || j >= n)
                return true;
            return !grid[i][j];
        }

        void place(int i, int j)
        {
            grid[i][j] = true;
            position[i] = j + 1;
        }

        void unplace(int i, int j)
        {
            grid[i][j] = false;
            position[i] = 0;
        }
    };

    bool safe(int i, int j, const int n, StateSpace &s)
    {
        for (int k = 0; k < i; k++)
        {
            if (!s.isSafe(i - k - 1, j, n) ||
                !s.isSafe(i - k - 1, j - k - 1, n) ||
                !s.isSafe(i - k - 1, j + k + 1, n))
                return false;
        }
        return true;
    }

    void placeQueen(int i, const int n, StateSpace &s, vector<vector<int>> &result)
    {
        if (i == n)
        {
            result.push_back(s.position);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (!safe(i, j, n, s))
                continue;
            s.place(i, j);
            placeQueen(i + 1, n, s, result);
            s.unplace(i, j);
        }
    }

public:
    vector<vector<int>> nQueen(int n)
    {
        // code here
        StateSpace s(n);
        vector<vector<int>> result;
        placeQueen(0, n, s, result);
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends