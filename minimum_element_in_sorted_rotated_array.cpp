#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int i = 0, j = nums.size() - 1, n = nums.size();
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] < nums[(mid + n - 1) % n] &&
                nums[mid] < nums[(mid + 1) % n])
                return nums[mid];
            if (nums[n - 1] < nums[mid])
                i = mid + 1;
            else
                j = mid - 1;
        }
        return nums[0];
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
        Solution ob;
        cout << ob.findMin(nums) << endl;
    }
    return 0;
}