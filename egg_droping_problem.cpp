#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int find_min_attempts(int n, int k, vector<vector<int>> &dp)
    {
        if (dp[n][k] != -1)
            return dp[n][k];
        if (n == 0 || k == 0)
            return dp[n][k] = 0;
        if (n == 1 || k == 1)
            return dp[n][k] = k;
        int minAttempts = k;
        for (int i = 1; i <= k; i++)
            minAttempts = min(minAttempts, 1 + max(find_min_attempts(n - 1, i - 1, dp),
                                                   find_min_attempts(n, k - i, dp)));
        return dp[n][k] = minAttempts;
    }

    int eggDrop(int n, int k)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return find_min_attempts(n, k, dp);
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
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends