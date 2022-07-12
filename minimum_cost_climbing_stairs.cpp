#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

    You can either start from the step with index 0, or the step with index 1.

    Return the minimum cost to reach the top of the floor.
    */
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = cost[0];
        for (int i = 2; i <= cost.size(); i++)
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i - 1];
        return min(dp[cost.size()], dp[cost.size() - 1]);
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
        vector<int> cost(n);
        for (int i = 0; i < n; i++)
            cin >> cost[i];
        Solution obj;
        cout << obj.minCostClimbingStairs(cost) << endl;
    }
    return 0;
}
