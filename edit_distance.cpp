#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1));
        for (int i = 0; i <= t.size(); i++)
        {
            for (int j = 0; j <= s.size(); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = max(i, j);
                else if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
        return dp[t.size()][s.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends