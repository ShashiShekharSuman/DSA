#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int product = 1, zeros = 0, n = nums.size();
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                zeros++;
            else
                product *= nums[i];
        }
        if (zeros > 1)
            return result;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                if (zeros - 1 > 0)
                    result[i] = 0;
                else
                    result[i] = product;
            }
            else
                result[i] = zeros > 0 ? 0 : product / nums[i];
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        vector<int> result = obj.productExceptSelf(nums);
        for (auto i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}