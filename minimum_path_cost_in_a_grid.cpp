#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int findMinPath(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<int> &dp)
    {
        int minCost = INT_MAX;
        if (dp[grid[r][c]] != -1)
            return dp[grid[r][c]];
        if (r == grid.size() - 1)
            return dp[grid[r][c]] = grid[r][c];
        for (int i = 0; i < grid[0].size(); i++)
        {
            minCost = min(minCost, moveCost[grid[r][c]][i] + findMinPath(r + 1, i, grid, moveCost, dp));
        }
        return dp[grid[r][c]] = minCost + grid[r][c];
    }

public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int n = grid.size(), m = grid[0].size(), minCost;
        vector<int> dp(n * m, -1);
        minCost = findMinPath(0, 0, grid, moveCost, dp);
        for (int i = 1; i < m; i++)
            minCost = min(minCost, findMinPath(0, i, grid, moveCost, dp));
        return minCost;
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
        vector<vector<int>> grid(n, vector<int>(m)), moveCost(n * m, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n * m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> moveCost[i][j];
            }
        }
        Solution obj;
        cout << obj.minPathCost(grid, moveCost) << "\n";
    }
    return 0;
}