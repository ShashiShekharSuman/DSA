#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        vector<int> minCoin(V + 1, INT_MAX);
        for (int i = 0; i <= V; i++)
        {
            if (i == 0)
            {
                minCoin[i] = 0;
                continue;
            }
            for (int j = 0; j < M; j++)
            {
                if (i - coins[j] > -1 && minCoin[i - coins[j]] != INT_MAX)
                    minCoin[i] = min(minCoin[i], minCoin[i - coins[j]] + 1);
            }
        }
        if (minCoin[V] == INT_MAX)
            return -1;
        return minCoin[V];
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, m, v) << "\n";
    }
    return 0;
}
// } Driver Code Ends