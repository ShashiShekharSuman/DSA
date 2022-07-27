#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

    Return a list of all k-distant indices sorted in increasing order.
    */
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            for (int j = max(i - k, 0); j < min((int)nums.size(), i + k + 1); j++)
                if (nums[j] == key)
                {
                    result.push_back(i);
                    break;
                }
        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, key, k;
        cin >> n >> key >> k;
        vector<int> nums(n);

        for (int i = 0; i < n; k++)
            cin >> nums[k];

        Solution obj;
        vector<int> res = obj.findKDistantIndices(nums, key, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}