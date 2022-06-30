#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int partition(const string &digits, int index, int prevSum, vector<vector<int>> &dp)
    {
        if (dp[index][prevSum] != -1)
            return dp[index][prevSum];
        if (index == digits.size())
            return dp[index][prevSum] = 1;
        int sum = 0, count = 0, i = index;
        while (sum + digits[i] - '0' < prevSum && i < digits.size())
            sum += digits[i++] - '0';
        while (i < digits.size())
        {
            sum += digits[i] - '0';
            count += partition(digits, i + 1, sum, dp);
            i++;
        }
        return dp[index][prevSum] = count;
    }

public:
    int TotalCount(string str)
    {
        // Code here
        // int count = 0;
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() * 9 + 1, -1));
        partition(str, 0, 0, dp);
        return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.TotalCount(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends