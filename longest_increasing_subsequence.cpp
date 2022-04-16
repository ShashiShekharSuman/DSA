#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find length of longest increasing subsequence.

    // DP using Longest Common Subsequence
    // int longestSubsequence(int n, int a[])
    // {
    //     set<int> s;
    //     for (int i = 0; i < n; i++)
    //         s.insert(a[i]);
    //     vector<int> b;
    //     for (auto i : s)
    //         b.push_back(i);

    //     vector<int> dp(n + 1, 0);
    //     for (int i = 0; i < b.size(); i++)
    //     {
    //         auto common = 0;
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (b[i] == a[j - 1])
    //                 swap(++common, dp[j]);
    //             else
    //             {
    //                 common = max(dp[j], dp[j - 1]);
    //                 swap(common, dp[j]);
    //             }
    //         }
    //     }
    //     return dp[n];
    // }

    // DP Method 2
    // int longestSubsequence(int n, int a[])
    // {
    //     int longestSubsequence = 0;
    //     vector<int> dp(n, 1);
    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (a[i] > a[j])
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //         longestSubsequence = max(longestSubsequence, dp[i]);
    //     }
    //     return longestSubsequence;
    // }

    int getIndex(vector<int> &tail, int l, int r, int key)
    {
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (tail[m] >= key)
                r = m;
            else
                l = m;
        }
        return r;
    }

    int longestSubsequence(int n, int a[])
    {
        if (n == 0)
            return 0;
        vector<int> tail(n, 0);
        int length = 1;
        tail[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] < tail[0])
                tail[0] = a[i];
            else if (a[i] > tail[length - 1])
                tail[length++] = a[i];
            else
                tail[getIndex(tail, -1, length - 1, a[i])] = a[i];
        }
        return length;
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends