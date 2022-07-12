#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.

    //  int knapSackUtil(int W, int wt[], int val[], int n, vector<vector<int>> &dp) {
    //      if (n == 0 || W == 0) return dp[n][W] = 0;
    //      if (dp[n][W] != -1) return dp[n][W];
    //      if (wt[n-1] > W) return dp[n][W] = knapSackUtil(W, wt, val, n-1, dp);
    //      else return dp[n][W] = max(knapSackUtil(W-wt[n-1], wt, val, n-1, dp) + val[n-1],
    //                                knapSackUtil(W, wt, val, n-1, dp));
    //  }

    // int knapSack(int W, int wt[], int val[], int n) {
    //   // Your code here
    //   int value = 0;
    //   vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    //   return knapSackUtil(W, wt, val, n, dp);
    // }

    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        int value = 0;
        vector<vector<int>> dp(W + 1, vector<int>(n + 1));
        for (int i = 0; i <= W; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (wt[j - 1] > i)
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = max(val[j - 1] + dp[i - wt[j - 1]][j - 1], dp[i][j - 1]);
            }
        }
        return dp[W][n];
    }
};

// { Driver Code Starts.

int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        // inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        // inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        // calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends