#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7,
        dx[4] = {1, 0, -1, 0},
        dy[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, int m, int n)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

    int dfs(int i, int j, int m, int n, int moves, vector<vector<vector<long long>>> &dp)
    {
        if (moves < 0)
            return 0;
        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];
        dp[i][j][moves] = 0;
        for (int k = 0; k < 4; k++)
        {
            if (isValid(i + dx[k], j + dy[k], m, n))
                dp[i][j][moves] += dfs(i + dx[k], j + dy[k], m, n, moves - 1, dp);
            else
                dp[i][j][moves]++;
            dp[i][j][moves] %= mod;
        }
        return dp[i][j][moves];
    }

public:
    /*
    There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

    Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.
    */
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(maxMove, -1)));
        return dfs(startRow, startColumn, m, n, maxMove - 1, dp);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, maxMove, startRow, startColumn;
        cin >> m >> n >> maxMove >> startRow >> startColumn;
        Solution obj;
        cout << obj.findPaths(m, n, maxMove, startRow, startColumn) << "\n";
    }
    return 0;
}