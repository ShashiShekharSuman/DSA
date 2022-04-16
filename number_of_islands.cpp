#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the number of islands.
    bool isValid(int i, int j, vector<vector<char>> &grid)
    {
        return i >= 0 &&
               i < grid.size() &&
               j >= 0 &&
               j < grid[0].size() &&
               grid[i][j] == '1';
    }

    void dfs(int i, int j, vector<bool> &visited, vector<vector<char>> &grid)
    {
        visited[i * grid[0].size() + j] = true;
        for (int p = -1; p < 2; p++)
        {
            for (int q = -1; q < 2; q++)
            {
                if ((p != 0 || q != 0) && isValid(i + p, j + q, grid))
                {
                    if (!visited[(i + p) * grid[0].size() + (j + q)])
                        dfs(i + p, j + q, visited, grid);
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<bool> visited(grid.size() * grid[0].size(), false);
        int islandCount = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !visited[i * grid[0].size() + j])
                {
                    dfs(i, j, visited, grid);
                    islandCount++;
                }
            }
        }
        return islandCount;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends