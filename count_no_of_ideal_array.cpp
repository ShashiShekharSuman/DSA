#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given two integers n and maxValue, which are used to describe an ideal array.
    A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:
        > Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
        > Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
    Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.
    */

    // Dynamic Programming
    int idealArrays(int n, int maxValue)
    {
        long long sum = 0, mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(maxValue, 0));
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < maxValue; j++)
            {
                if (i == 0)
                    dp[i][j] = 1;
                for (int k = j; k < maxValue; k += j + 1)
                {
                    dp[i + 1][k] += dp[i][j];
                    dp[i + 1][k] %= mod;
                }
            }
        }
        for (int i = 0; i < maxValue; i++)
        {
            sum += dp[n - 1][i];
            sum %= mod;
        }
        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxValue;
        cin >> n >> maxValue;
        Solution obj;
        cout << obj.idealArrays(n, maxValue) << endl;
    }
    return 0;
}