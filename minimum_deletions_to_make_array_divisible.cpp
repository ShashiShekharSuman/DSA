#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
    Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.
    Note that an integer x divides y if y % x == 0.
    */
    int minOperations(vector<int> &nums, vector<int> &numsDivide)
    {
        int gcd = numsDivide[0], deletions = nums.size();
        for (int i = 1; i < numsDivide.size(); i++)
            gcd = __gcd(gcd, numsDivide[i]);
        // return gcd;
        sort(nums.begin(), nums.end());
        for (int i = 1; i * i <= gcd; i++)
        {
            if (gcd % i == 0)
            {
                auto it1 = lower_bound(nums.begin(), nums.end(), i),
                     it2 = lower_bound(nums.begin(), nums.end(), gcd / i);
                if (it1 != nums.end() && *it1 == i)
                    deletions = min((long long)deletions, it1 - nums.begin());
                if (it2 != nums.end() && *it2 == gcd / i)
                    deletions = min((long long)deletions, it2 - nums.begin());
            }
        }
        return deletions == nums.size() ? -1 : deletions;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n), numsDivide(m);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        for (int i = 0; i < m; i++)
            cin >> numsDivide[i];
        Solution obj;
        cout << obj.minOperations(nums, numsDivide) << endl;
    }
    return 0;
}