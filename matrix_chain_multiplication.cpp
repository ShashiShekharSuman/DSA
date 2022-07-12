// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int mcm(int arr[], int l, int h, vector<vector<int>> &dp)
    {
        if (dp[l][h] != INT_MAX)
            return dp[l][h];
        if (h - l < 3)
            return dp[l][h] = 0;

        for (int i = l + 1; i < h; i++)
            dp[l][h] = min(
                dp[l][h],
                mcm(arr, l, i + 1, dp) + mcm(arr, i, h, dp) + arr[l] * arr[i] * arr[h - 1]);
        return dp[l][h];
    }

public:
    /*
    Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

    The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).
    */
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MAX));
        return mcm(arr, 0, N, dp);
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
} // } Driver Code Ends