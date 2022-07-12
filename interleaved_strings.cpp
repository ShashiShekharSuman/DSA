// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*
    Given strings A, B, and C, find whether C is formed by an interleaving of A and B.
    An interleaving of two strings S and T is a configuration such that it creates a new string Y from the concatenation substrings of A and B and |Y| = |A + B| = |C|
    For example:
    A = "XYZ"
    B = "ABC"
    so we can make multiple interleaving string Y like, XYZABC, XAYBCZ, AXBYZC, XYAZBC and many more so here your task is to check whether you can create a string Y which can be equal to C.
    Specifically, you just need to create substrings of string A and create substrings B and concatenate them and check whether it is equal to C or not.
    Note: a + b is the concatenation of strings a and b.
    Return true if C is formed by an interleaving of A and B, else return false.
    */

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
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] && (C[j - 1] == B[j - 1]);
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] && (C[i - 1] == A[i - 1]);
                else
                    dp[i][j] = (dp[i - 1][j] && (C[i + j - 1] == A[i - 1])) || (dp[i][j - 1] && (C[i + j - 1] == B[j - 1]));
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