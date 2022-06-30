
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    int dx[4] = {1, 0, -1, 0},
        dy[4] = {0, 1, 0, -1};
        
    bool isValid(int i, int j, const vector<vector<int>> &matrix) {
        return i >= 0 && j >= 0 && i < matrix.size() && j < matrix[0].size() && matrix[i][j] != 0;
    }
    
    int traverse(int i, int j, int &xd, int &yd, int p, const vector<vector<int>> &matrix, vector<vector<bool>> &visited) {
        if (i == xd && j == yd) return p;
        int lp = -1;
        visited[i][j] = true;
        
        for (int k = 0; k < 4; k++) 
            if (isValid(i+dx[k], j+dy[k], matrix) && !visited[i+dx[k]][j+dy[k]]) 
                lp = max(lp, traverse(i+dx[k], j+dy[k], xd, yd, p+1, matrix, visited));

        visited[i][j] = false;
        return lp;
    }
    
    
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if (!isValid(xs, ys, matrix)) return -1;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        return traverse(xs, ys, xd, yd, 0, matrix, visited);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends