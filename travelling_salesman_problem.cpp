
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int travel(vector<vector<int>> &cost, int n, int x, unordered_set<int> &s)
    {
        if (s.size() == n - 1)
            return cost[x][0];
        int minCost = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            if (s.find(i) != s.end())
                continue;
            s.insert(i);
            minCost = min(minCost, cost[x][i] + travel(cost, n, i, s));
            s.erase(i);
        }
        return minCost;
    }

public:
    /*
    Given a matrix cost of size n where cost[i][j] denotes the cost of moving from city i to city j. Your task is to complete a tour from the city 0 (0 based index) to all other cities such that you visit each city atmost once and then at the end come back to city 0 in min cost.
    */
    int total_cost(vector<vector<int>> &cost)
    {
        // Code here
        int n = cost.size();
        unordered_set<int> s;
        return travel(cost, n, 0, s);
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends