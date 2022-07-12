// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    bool isPalindrome(string &str, int i, int j)
    {
        while (i < j)
            if (str[i++] != str[j--])
                return false;
        return true;
    }

    int partition(int l, int h, string &str, vector<vector<int>> &dp)
    {
        if (dp[l][h] != INT_MAX)
            return dp[l][h];
        if (isPalindrome(str, l, h - 1))
            return dp[l][h] = 0;
        for (int i = l + 1; i < h; i++)
        {
            dp[l][h] = min(dp[l][h], partition(l, i, str, dp) + partition(i, h, str, dp) + 1);
        }
        return dp[l][h];
    }

public:
    /*
    Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.
    */
    int palindromicPartition(string str)
    {
        // code here
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1, INT_MAX));
        partition(0, str.size(), str, dp);
        return dp[0][str.size()];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
} // } Driver Code Ends