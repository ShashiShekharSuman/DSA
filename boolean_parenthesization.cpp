// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    int mod = 1003;
    vector<int> solve(string &S, int l, int h, vector<vector<vector<int>>> &dp)
    {
        if (dp[l][h][0] != -1)
            return dp[l][h];
        int t_count = 0, f_count = 0;
        if (h - l == 1)
        {
            if (S[l] == 'T')
                t_count = 1;
            else
                f_count = 1;
            return dp[l][h] = {t_count, f_count};
        }
        for (int i = l; i < h; i++)
        {
            if (S[i] == 'T' || S[i] == 'F')
                continue;
            solve(S, l, i, dp);
            solve(S, i + 1, h, dp);
            if (S[i] == '&')
            {
                t_count += dp[l][i][0] * dp[i + 1][h][0];
                t_count %= mod;
                f_count += dp[l][i][1] * dp[i + 1][h][0] + dp[l][i][0] * dp[i + 1][h][1] + dp[l][i][1] * dp[i + 1][h][1];
                f_count %= mod;
            }
            else if (S[i] == '|')
            {
                f_count += dp[l][i][1] * dp[i + 1][h][1];
                f_count %= mod;
                t_count += dp[l][i][1] * dp[i + 1][h][0] + dp[l][i][0] * dp[i + 1][h][1] + dp[l][i][0] * dp[i + 1][h][0];
                t_count %= mod;
            }
            else
            {
                t_count += dp[l][i][1] * dp[i + 1][h][0] + dp[l][i][0] * dp[i + 1][h][1];
                t_count %= mod;
                f_count += dp[l][i][0] * dp[i + 1][h][0] + dp[l][i][1] * dp[i + 1][h][1];
                f_count %= mod;
            }
        }
        return dp[l][h] = {t_count, f_count};
    }

public:
    /*
    Given a boolean expression S of length N with following symbols.
    Symbols
        'T' ---> true
        'F' ---> false
    and following operators filled between symbols
    Operators
        &   ---> boolean AND
        |   ---> boolean OR
        ^   ---> boolean XOR
    Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.
    */
    int countWays(int N, string S)
    {
        // code here
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(2, -1)));
        solve(S, 0, N, dp);
        return dp[0][N][0];
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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    return 0;
} // } Driver Code Ends