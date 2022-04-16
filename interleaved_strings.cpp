// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */

    bool isInterleave(string A, string B, string C)
    {
        // Your code here
        if (A.size() + B.size() != C.size())
            return false;
        vector<vector<bool>> dp(A.size() + 1, vector<bool>(B.size() + 1));
        for (int i = 0; i <= A.size(); i++)
        {
            for (int j = 0; j <= B.size(); j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = true;
                    continue;
                }
                if (A[i - 1] == C[i + j - 1])
                    dp[i][j] = dp[i - 1][j];
                if (B[j - 1] == C[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
                if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
        return dp[A.size()][B.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        cout << obj.isInterleave(a, b, c) << endl;
    }
    // your code goes here
    return 0;
} // } Driver Code Ends