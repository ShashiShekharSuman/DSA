// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum % 2 != 0)
            return 0;
        sum /= 2;
        vector<vector<int>> dp(sum + 1, vector<int>(N + 1));
        for (int i = 0; i <= sum; i++)
        {
            for (int j = 0; j <= N; j++)
            {
                if (i == 0)
                    dp[i][j] = 1;
                else if (j == 0)
                    dp[i][j] = 0;
                else if (i < arr[j - 1])
                    dp[i][j] = dp[i][j - 1];
                else
                    dp[i][j] = dp[i][j - 1] || dp[i - arr[j - 1]][j - 1];
            }
        }
        return dp[sum][N];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends