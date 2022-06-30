#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
    In one move, you can increment or decrement an element of the array by 1.
    Test cases are designed so that the answer will fit in a 32-bit integer.
    */
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size(), count = 0;
        nth_element(nums.begin(), nums.begin() + (n / 2), nums.end());
        for (auto num : nums)
            count += abs(num - nums[n / 2]);
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        Solution obj;
        cout << obj.minMoves2(nums) << '\n';
    }
    return 0;
}