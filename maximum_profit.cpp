// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Intuition
    //  dp[K][N] = max(dp[K-1][N], (dp[K-1][j-1] + A[N-1]-A[j-2] for 1 <= i <= N))
    //  Optimisation
    //  keep tract of maximum dp[K-1][j-1] - A[j-2]
    int maxProfit(int K, int N, int A[])
    {
        // code here
        int profit;
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        for (int i = 0; i <= K; i++)
        {
            profit = INT_MIN;
            for (int j = 0; j <= N; j++)
            {
                if (i == 0 || j == 0 || j == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }
                profit = max(profit, dp[i - 1][j - 1] - A[j - 2]);
                dp[i][j] = max(dp[i][j - 1], profit + A[j - 1]);
            }
        }
        return dp[K][N];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} // } Driver Code Ends