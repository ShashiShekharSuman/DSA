#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int dx[4] = {-1, 1, 0, 0},
        dy[4] = {0, 0, -1, 1};

    bool isValid(int i, int j, const vector<vector<int>> &grid)
    {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid.size() && grid[i][j] != 0;
    }

    bool dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (grid[i][j] == 2)
            return true;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            if (!isValid(i + dx[k], j + dy[k], grid))
                continue;
            if (dfs(i + dx[k], j + dy[k], grid))
                return true;
        }
        return false;
    }

public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        // code here
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i][j] == 1)
                    return dfs(i, j, grid);

        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
} // } Driver Code Ends