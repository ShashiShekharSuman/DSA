#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2, j = nums.size() - 1;
        while (i > -1 && nums[i] >= nums[i + 1])
            i--;
        if (i != -1)
        {
            while (j > i && nums[i] >= nums[j])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + ++i, nums.end());
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
        obj.nextPermutation(nums);
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}