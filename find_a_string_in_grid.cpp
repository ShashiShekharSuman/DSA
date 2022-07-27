#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0},
        dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};

    bool isValid(int i, int j, const vector<vector<char>> &grid)
    {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    bool found(int i, int j, string &word, int index, vector<vector<char>> &grid, int k = -1)
    {
        if (index == word.size())
            return true;
        if (!isValid(i, j, grid) || grid[i][j] != word[index++])
            return false;

        if (k != -1)
            return found(i + dx[k], j + dy[k], word, index, grid, k);
        else
            for (k = 0; k < 8; k++)
                if (found(i + dx[k], j + dy[k], word, index, grid, k))
                    return true;

        return false;
    }

public:
    /*
    Given a 2D grid of n*m of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form). The 8 directions are, horizontally left, horizontally right, vertically up, vertically down and 4 diagonal directions.
    */
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word)
    {
        vector<vector<int>> result;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (found(i, j, word, 0, grid))
                    result.push_back({i, j});

        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, 'x'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }
        string word;
        cin >> word;
        Solution obj;
        vector<vector<int>> ans = obj.searchWord(grid, word);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
        if (ans.size() == 0)
        {
            cout << "-1\n";
        }
    }
    return 0;
}
// } Driver Code Ends