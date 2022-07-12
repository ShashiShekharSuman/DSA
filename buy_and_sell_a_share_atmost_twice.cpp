// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). The stock prices throughout the day  are represented in the form of an array price.

Given an array price of size N, find out the maximum profit that a share trader could have made.
*/
int maxProfit(vector<int> &price)
{
    // Write your code here..
    vector<vector<int>> dp(price.size(), vector<int>(3, 0));

    for (int i = 1; i < 3; i++)
    {
        int mx = -price[0];
        for (int j = 1; j < price.size(); j++)
        {
            dp[j][i] = max(dp[j - 1][i], price[j] + mx);
            mx = max(mx, dp[j][i - 1] - price[j]);
        }
    }
    return dp[price.size() - 1][2];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        cout << maxProfit(price) << endl;
    }
}
// } Driver Code Ends