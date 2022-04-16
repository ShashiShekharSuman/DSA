#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    bool isValid(int i, int j, int n)
    {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

public:
    // Function to return the minimum cost to react at bottom
    // right cell from top left cell.
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        typedef pair<int, pair<int, int>> pip;
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        priority_queue<pip, vector<pip>, greater<pip>> pq;
        distance[0][0] = grid[0][0];
        pq.push({distance[0][0], {0, 0}});
        int dx[4] = {0, 0, 1, -1},
            dy[4] = {1, -1, 0, 0};
        while (!pq.empty())
        {
            int i = pq.top().second.first,
                j = pq.top().second.second;
            pq.pop();
            if (i == n - 1 && j == n - 1)
                break;
            for (int k = 0; k < 4; k++)
            {
                if (isValid(i + dx[k], j + dy[k], n) &&
                    distance[i + dx[k]][j + dy[k]] >= distance[i][j] + grid[i + dx[k]][j + dy[k]])
                {
                    distance[i + dx[k]][j + dy[k]] = distance[i][j] + grid[i + dx[k]][j + dy[k]];
                    pq.push({distance[i + dx[k]][j + dy[k]], {i + dx[k], j + dy[k]}});
                }
            }
        }
        return distance[n - 1][n - 1];
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
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends