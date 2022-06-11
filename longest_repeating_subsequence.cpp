#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        // Code here
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1));
        for (int i = 0; i <= str.size(); i++)
        {
            for (int j = 0; j <= str.size(); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (i != j && str[i - 1] == str[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
        return dp[str.size()][str.size()];
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
        Solution obj;
        int ans = obj.LongestRepeatingSubsequence(str);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends