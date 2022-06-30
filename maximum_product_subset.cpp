/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int findMaxProduct(vector<int> &a, int n)
    {
        // Write your code here
        if (n == 1)
            return a[0];
        long long p = 1, mod = 1e9 + 7;
        int zero = 0, maxNeg = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                zero++;
                continue;
            }
            else if (a[i] < 0)
                maxNeg = max(maxNeg, a[i]);
            p *= a[i];
            p %= mod;
        }
        if (zero == n || (p < 0 && zero == n - 1))
            return 0;
        if (p < 0)
            p /= maxNeg;
        return p;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends