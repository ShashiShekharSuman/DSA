// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

    int solve(int keys[], int freq[], int l, int h, vector<vector<int>> &dp)
    {
        if (dp[l][h] != INT_MAX)
            return dp[l][h];
        if (l == h)
            return dp[l][h] = 0;
        for (int i = l; i < h; i++)
        {
            dp[l][h] = min(
                dp[l][h],
                freq[i] - (i > 0 ? freq[i - 1] : 0) +
                    solve(keys, freq, l, i, dp) + (i > 0 ? freq[i - 1] - (l > 0 ? freq[l - 1] : 0) : 0) +
                    solve(keys, freq, i + 1, h, dp) + freq[h - 1] - freq[i]);
        }
        return dp[l][h];
    }

public:
    /*
    Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts, where freq[i] is the number of searches to keys[i]. Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
    Let us first define the cost of a BST. The cost of a BST node is level of that node multiplied by its frequency. Level of root is 1.
    */
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        for (int i = 1; i < n; i++)
            freq[i] += freq[i - 1];
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        solve(keys, freq, 0, n, dp);
        return dp[0][n];
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
        int keys[n];
        for (int i = 0; i < n; i++)
            cin >> keys[i];
        int freq[n];
        for (int i = 0; i < n; i++)
            cin >> freq[i];
        Solution ob;
        cout << ob.optimalSearchTree(keys, freq, n) << endl;
    }
    return 0;
} // } Driver Code Ends