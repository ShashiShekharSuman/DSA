#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// } Driver Code Ends

class Solution
{
    class StateSpace
    {
        vector<vector<bool>> row, col, compartment;

    public:
        StateSpace(const int grid[N][N])
        {
            row = vector<vector<bool>>(N, vector<bool>(N, false)),
            col = vector<vector<bool>>(N, vector<bool>(N, false)),
            compartment = vector<vector<bool>>(N, vector<bool>(N, false));

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == 0)
                        continue;
                    row[i][grid[i][j] - 1] = true;
                    col[j][grid[i][j] - 1] = true;
                    compartment[i / 3 * 3 + j / 3][grid[i][j] - 1] = true;
                }
            }
        }

        bool isValid(int i, int j, int number)
        {
            return !row[i][number] &&
                   !col[j][number] &&
                   !compartment[i / 3 * 3 + j / 3][number];
        }

        void visit(int grid[N][N], int i, int j, int number)
        {
            grid[i][j] = number + 1;
            row[i][number] = true;
            col[j][number] = true;
            compartment[i / 3 * 3 + j / 3][number] = true;
        }

        void unvisit(int grid[N][N], int i, int j, int number)
        {
            grid[i][j] = 0;
            row[i][number] = false;
            col[j][number] = false;
            compartment[i / 3 * 3 + j / 3][number] = false;
        }
    };

    bool solve(int grid[N][N], int i, int j, StateSpace &s)
    {
        if (i == N)
            return true;
        if (j == N)
            return solve(grid, i + 1, 0, s);
        if (grid[i][j] != 0)
            return solve(grid, i, j + 1, s);

        for (int k = 0; k < N; k++)
        {
            if (!s.isValid(i, j, k))
                continue;
            s.visit(grid, i, j, k);
            if (solve(grid, i, j + 1, s))
                return true;
            s.unvisit(grid, i, j, k);
        }

        return false;
    }

public:
    // Function to find a solved Sudoku.
    bool SolveSudoku(int grid[N][N])
    {
        // Your code here
        StateSpace s(grid);
        return solve(grid, 0, 0, s);
    }

    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N])
    {
        // Your code here
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int grid[N][N];

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                cin >> grid[i][j];

        Solution ob;

        if (ob.SolveSudoku(grid) == true)
            ob.printGrid(grid);
        else
            cout << "No solution exists";

        cout << endl;
    }

    return 0;
} // } Driver Code Ends