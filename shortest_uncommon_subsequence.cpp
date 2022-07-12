#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int shortestUnSub(string S, string T)
    {
        // code here
        int minLen = INT_MAX;
        vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1));
        for (int i = 0; i <= S.size(); i++)
        {
            for (int j = 0; j <= T.size(); j++)
            {
                if (i == 0)
                    dp[i][j] = 1e3;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                {
                    int k = j;
                    while (S[i - 1] != T[k - 1] && k > 0)
                        k--;
                    if (k == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j], dp[i - 1][k - 1] + 1);
                }
            }
        }
        return dp[S.size()][T.size()] == 1e3 ? -1 : dp[S.size()][T.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, T;
        cin >> S >> T;

        Solution ob;
        cout << ob.shortestUnSub(S, T) << endl;
    }
    return 0;
} // } Driver Code Ends