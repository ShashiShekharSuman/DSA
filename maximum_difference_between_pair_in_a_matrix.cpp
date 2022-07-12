/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    Given an N x N matrix, mat[N][N] of integers. The task is to find the maximum value of mat(c, d) - mat(a, b) over all choices of indexes such that both c > a and d > b.
    */
    int findMaxValue(vector<vector<int>> &mat, int N)
    {
        // Write your code here
        int difference = INT_MIN;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = INT_MAX;
                else
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), mat[i - 1][j - 1]);
                if (i > 1 && j > 1)
                    difference = max(difference, mat[i - 1][j - 1] - dp[i - 1][j - 1]);
            }
        }
        return difference;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.findMaxValue(mat, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends