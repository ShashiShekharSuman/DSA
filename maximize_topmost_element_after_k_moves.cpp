#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given a 0-indexed integer array nums representing the contents of a pile, where nums[0] is the topmost element of the pile.

    In one move, you can perform either of the following:
        > If the pile is not empty, remove the topmost element of the pile.
        > If there are one or more removed elements, add any one of them back onto the pile. This element becomes the new topmost element.

    You are also given an integer k, which denotes the total number of moves to be made.

    Return the maximum value of the topmost element of the pile possible after exactly k moves. In case it is not possible to obtain a non-empty pile after k moves, return -1.
    */
    int maximumTop(vector<int> &nums, int k)
    {
        if (k == 0)
            return nums.size() > 0 ? nums[0] : -1;
        if (nums.size() == 1)
            return (k & 1) ? -1 : nums[0];
        if (k == 1)
            return nums.size() < 2 ? -1 : nums[1];
        return nums.size() < k ? *max_element(nums.begin(), nums.begin() + min(k - 1, (int)nums.size())) : max(nums[k], *max_element(nums.begin(), nums.begin() + min(k - 1, (int)nums.size())));
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        cout << obj.maximumTop(nums, k) << endl;
    }
    return 0;
}