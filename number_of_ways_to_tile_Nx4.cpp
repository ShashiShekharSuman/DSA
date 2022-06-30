// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Given a value N. In how many ways you can construct a grid of size N x 4 using tiles of size 1 x 4.
    long long int arrangeTiles(int N)
    {
        // code here
        long long dp[N + 1];
        dp[0] = 1;
        for (int i = 1; i <= N; i++)
            dp[i] = dp[i - 1] + (i > 3 ? dp[i - 4] : 0);
        return dp[N];
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

        Solution ob;
        cout << ob.arrangeTiles(N) << "\n";
    }
    return 0;
} // } Driver Code Ends