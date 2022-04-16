#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        // vector<vector<int>> sol_matrix(s2.size() + 1, vector<int>(s1.size() + 1));

        // for (int i = 0; i <= s2.size(); i++)
        // {
        //     for (int j = 0; j <= s1.size(); j++)
        //     {

        //         if (i == 0 || j == 0)
        //             sol_matrix[i][j] = 0;

        //         else if (s2[i - 1] == s1[j - 1])
        //             sol_matrix[i][j] = 1 + sol_matrix[i - 1][j - 1];

        //         else
        //             sol_matrix[i][j] = max(sol_matrix[i - 1][j], sol_matrix[i][j - 1]);
        //     }
        // }
        // return sol_matrix[s2.size()][s1.size()];

        vector<int> dp(s1.size() + 1, 0);

        for (int i = 0; i < s2.size(); i++)
        {
            auto common = 0;
            for (int j = 1; j <= s1.size(); j++)
            {
                if (s2[i] == s1[j - 1])
                {
                    common++;
                    swap(common, dp[j]);
                }
                else
                {
                    common = max(dp[j], dp[j - 1]);
                    swap(common, dp[j]);
                }
            }
        }
        return dp[s1.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends