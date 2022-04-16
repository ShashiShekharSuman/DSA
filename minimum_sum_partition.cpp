#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        vector<bool> dp(sum / 2 + 1);
        for (int i = 0; i <= n; i++)
        {
            for (int j = sum / 2; j >= 0; j--)
            {
                if (j == 0)
                    dp[j] = true;
                else if (i == 0)
                    dp[j] = false;
                else if (arr[i - 1] <= j)
                    dp[j] = dp[j] || dp[j - arr[i - 1]];
            }
        }
        for (int i = sum / 2; i >= 0; i--)
            if (dp[i])
                return sum - 2 * i;
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

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.minDifference(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends