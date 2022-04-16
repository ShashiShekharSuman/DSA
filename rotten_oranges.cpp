#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.

    bool isValid(int i, int j, const vector<vector<int>> &grid)
    {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == 1;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int dx[4] = {-1, 1, 0, 0},
            dy[4] = {0, 0, -1, 1},
            minTime = 0;

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 2)
                    q.push({0, {i, j}});

        while (!q.empty())
        {
            pair<int, int> coords = q.front().second;
            for (int i = 0; i < 4; i++)
                if (isValid(coords.first + dx[i], coords.second + dy[i], grid))
                {
                    grid[coords.first + dx[i]][coords.second + dy[i]] = 2;
                    q.push({q.front().first + 1, {coords.first + dx[i], coords.second + dy[i]}});
                }
            minTime = q.front().first;
            q.pop();
        }

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    return -1;

        return minTime;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends