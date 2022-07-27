#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given a 0-indexed array of strings nums, where each string is of equal length and consists of only digits.

    You are also given a 0-indexed 2D integer array queries where queries[i] = [ki, trimi]. For each queries[i], you need to:

        > Trim each number in nums to its rightmost trimi digits.
        > Determine the index of the kith smallest trimmed number in nums. If two trimmed numbers are equal, the number with the lower index is considered to be smaller.
        > Reset each number in nums to its original length.

    Return an array answer of the same length as queries, where answer[i] is the answer to the ith query.
    */
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> result, len;
        priority_queue<pair<string, int>> pq;
        for (auto q : queries)
        {
            pq = priority_queue<pair<string, int>>();
            for (int i = 0; i < nums.size(); i++)
            {
                pq.push({nums[i].substr(nums[i].size() - q[1]), i});
                if (pq.size() > q[0])
                    pq.pop();
            }
            result.push_back(pq.top().second);
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
        int n, q;
        cin >> n >> q;
        vector<string> nums(n);
        vector<vector<int>> queries(q, vector<int>(2));
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        for (int i = 0; i < q; i++)
            cin >> queries[i][0] >> queries[i][1];
        Solution obj;
        vector<int> result = obj.smallestTrimmedNumbers(nums, queries);
        for (auto i : result)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}