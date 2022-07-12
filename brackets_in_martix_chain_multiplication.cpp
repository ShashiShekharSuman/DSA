// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    pair<int, string> mcm(int p[], int n, int i, int j, vector<vector<pair<int, string>>> &dp)
    {
        if (dp[i][j].first != INT_MAX)
            return dp[i][j];
        if (j - i < 2)
            return {0, ""};
        if (j - i == 2)
            return {0, string(1, char(i + 'A'))};

        for (int k = i + 1; k < n - 1; k++)
        {
            pair<int, string> left = mcm(p, n, i, k + 1, dp),
                              right = mcm(p, n, k, j, dp);
            int cost = left.first + right.first + p[i] * p[k] * p[j - 1];
            if (cost < dp[i][j].first)
            {
                dp[i][j].first = cost;
                dp[i][j].second = '(' + left.second + right.second + ')';
            }
        }
        return dp[i][j];
    }

public:
    /*
    Given an array p[] of length n used to denote the dimensions of a series of matrices such that dimension of i'th matrix is p[i] * p[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together.
    The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications such that you need to perform minimum number of multiplications. There are many options to multiply a chain of matrices because matrix multiplication is associative i.e. no matter how one parenthesize the product, the result will be the same.
    */
    string matrixChainOrder(int p[], int n)
    {
        // code here
        vector<vector<pair<int, string>>> dp(n + 1, vector<pair<int, string>>(n + 1, {INT_MAX, ""}));
        return mcm(p, n, 0, n, dp).second;
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
        int p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i];

        Solution ob;
        cout << ob.matrixChainOrder(p, n) << "\n";
    }
    return 0;
} // } Driver Code Ends