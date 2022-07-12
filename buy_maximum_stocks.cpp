/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where price[i] denotes the price of the stock on the ith day.
    There is a rule that a customer can buy at most i stock on the ith day.
    If the customer has an amount of k amount of money initially. The task is to find out the maximum number of stocks a customer can buy.
    */
    int buyMaximumProducts(int n, int k, int price[])
    {
        // Write your code here
        vector<vector<int>> indexedPrices;
        for (int i = 0; i < n; i++)
            indexedPrices.push_back({price[i], i + 1});
        sort(indexedPrices.begin(), indexedPrices.end());
        int i = 0, count = 0;
        while (i < n && k >= indexedPrices[i][0])
        {
            count += min(k / indexedPrices[i][0], indexedPrices[i][1]);
            k -= min(k / indexedPrices[i][0], indexedPrices[i][1]) * indexedPrices[i][0];
            i++;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int price[n];
        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }
        Solution ob;
        int ans = ob.buyMaximumProducts(n, k, price);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends