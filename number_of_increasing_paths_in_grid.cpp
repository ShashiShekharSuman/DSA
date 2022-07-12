#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 1e9 + 7,
              dx[4] = {1, -1, 0, 0},
              dy[4] = {0, 0, 1, -1};

    bool isValid(int i, int j, int k, const vector<vector<int>> &grid)
    {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] > k);
    }

    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<long long>> &dp)
    {
        dp[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k],
                y = j + dy[k];
            if (!isValid(x, y, grid[i][j], grid))
                continue;
            if (dp[x][y] != -1)
                dp[i][j] += dp[x][y];
            else
                dp[i][j] += dfs(x, y, grid, dp);
            dp[i][j] %= mod;
        }
        return dp[i][j];
    }

public:
    /*
    You are given an m x n integer matrix grid, where you can move from a cell to any adjacent cell in all 4 directions.

    Return the number of strictly increasing paths in the grid such that you can start from any cell and end at any cell. Since the answer may be very large, return it modulo 109 + 7.

    Two paths are considered different if they do not have exactly the same sequence of visited cells.
    */
    int countPaths(vector<vector<int>> &grid)
    {
        long long paths = 0;
        vector<vector<long long>> dp(grid.size(), vector<long long>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (dp[i][j] == -1)
                    dfs(i, j, grid, dp);
                paths += dp[i][j];
                paths %= mod;
            }
        }
        return paths;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];

        Solution obj;
        cout << obj.countPaths(grid) << "\n";
    }
    return 0;
}