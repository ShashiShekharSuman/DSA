// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{

    int countSpace(vector<int> &nums, int index, int k, vector<int> &dp)
    {
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int space = 0, length = 0, cost = INT_MAX;
        for (int i = index; i < nums.size(); i++)
        {
            length += nums[i];
            if (length > k)
                break;
            if (i < nums.size() - 1)
                cost = min(cost, (k - length) * (k - length) + countSpace(nums, i + 1, k, dp));
            else
                cost = countSpace(nums, i + 1, k, dp);
            length++;
        }
        return dp[index] = cost;
    }

public:
    int solveWordWrap(vector<int> nums, int k)
    {
        // Code here
        vector<int> dp(nums.size(), -1);
        return countSpace(nums, 0, k, dp);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
} // } Driver Code Ends