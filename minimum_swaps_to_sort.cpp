#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        int n = nums.size(), minSwaps = 0;
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < n; i++)
            indexed_nums.push_back({nums[i], i});
        sort(indexed_nums.begin(), indexed_nums.end());

        for (int i = 0; i < n; i++)
        {
            while (i != indexed_nums[i].second)
            {
                swap(indexed_nums[i], indexed_nums[indexed_nums[i].second]);
                minSwaps++;
            }
        }
        return minSwaps;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends