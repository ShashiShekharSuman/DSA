// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    Given an array, arr[] of size N represents N house built along a straight line with equal distance between adjacent houses. Each house has a certain number of wine and they want to buy/sell those wines to other houses. Transporting one bottle of wine from one house to an adjacent house results in one unit of work. The task is to find the minimum number of work is required to fulfill all the demands of those N houses.

    if a[i] < 0, then ith house wants to sell a[i] number of a wine bottle to other houses.
    if a[i] > 0, then ith house wants to buy a[i] number of a wine bottle from other houses.
    Note: One have to print the minimum number such that, all the house can buy/sell wine to each other.
    It is guaranteed that sum of all the elements of the array will be 0.
    */
    int wineSelling(vector<int> &a)
    {
        // Code here.
        int cost = 0;
        for (int i = 1; i < a.size(); i++)
        {
            cost += abs(a[i - 1]);
            a[i] += a[i - 1];
        }
        return cost;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        int ans = ob.wineSelling(a);

        cout << ans << endl;
    }
} // } Driver Code Ends