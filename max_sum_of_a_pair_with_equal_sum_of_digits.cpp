#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int digitSum(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

public:
    /*
    You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

    Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
    */
    int maximumSum(vector<int> &nums)
    {
        int sum = -1;
        unordered_map<int, vector<int>> numbers;
        for (auto num : nums)
            numbers[digitSum(num)].push_back(num);
        for (auto i : numbers)
        {
            if (i.second.size() < 2)
                continue;
            int a = i.second[0], b = i.second[1];
            if (a < b)
                swap(a, b);
            for (int j = 2; j < i.second.size(); j++)
            {
                if (i.second[j] > a)
                {
                    swap(a, b);
                    a = i.second[j];
                }
                else if (i.second[j] > b)
                    b = i.second[j];
            }
            sum = max(sum, a + b);
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
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        cout << obj.maximumSum(nums) << endl;
    }
    return 0;
}