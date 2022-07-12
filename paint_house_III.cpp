#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.
    A neighborhood is a maximal group of continuous houses that are painted with the same color.
        > For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

    Given an array houses, an m x n matrix cost and an integer target where:
        > houses[i]: is the color of the house i, and 0 if the house is not painted yet.
        > cost[i][j]: is the cost of paint the house i with the color j + 1.
    Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.
    */
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n)));
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == 0 && j == 0)
                        dp[i][j][k] = 0;
                    else if (i == 0 || j == 0 || (houses[i - 1] != 0 && k != houses[i - 1] - 1))
                        dp[i][j][k] = INT_MAX;
                    else
                    {
                        dp[i][j][k] = dp[i - 1][j][k];
                        for (int p = 0; p < n; p++)
                        {
                            if (p == k)
                                continue;
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][p]);
                        }
                        if (houses[i - 1] == 0 && dp[i][j][k] != INT_MAX)
                            dp[i][j][k] += cost[i - 1][k];
                    }
                }
            }
        }
        int minCost = *min_element(dp[m][target].begin(), dp[m][target].end());
        return minCost == INT_MAX ? -1 : minCost;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, target;
        vector<int> houses(m);
        vector<vector<int>> cost(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            cin >> houses[i];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        cin >> target;
        Solution obj;
        cout << obj.minCost(houses, cost, m, n, target) << endl;
    }
    return 0;
}