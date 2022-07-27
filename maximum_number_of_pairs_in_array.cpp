#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given a 0-indexed integer array nums. In one operation, you may do the following:
        > Choose two integers in nums that are equal.
        > Remove both integers from nums, forming a pair.

    The operation is done on nums as many times as possible.
    Return a 0-indexed integer array answer of size 2 where answer[0] is the number of pairs that are formed and answer[1] is the number of leftover integers in nums after doing the operation as many times as possible.
    */
    vector<int> numberOfPairs(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        int answer = 0, leftover;
        for (auto i : m)
            if (~(i.second & 1))
                answer += i.second / 2;
        leftover = nums.size() - 2 * answer;
        return {answer, leftover};
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
        vector<int> result = obj.numberOfPairs(nums);
        cout << result[0] << " " << result[1] << endl;
    }
    return 0;
}