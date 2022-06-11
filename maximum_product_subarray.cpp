#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long maxProduct = INT_MIN, p1 = 1, p2 = 1;
        for (int i = 0; i < n; i++)
        {
            p1 *= arr[i];
            p2 *= arr[i];
            maxProduct = max(maxProduct, p1);
            maxProduct = max(maxProduct, p2);
            if (arr[i] < 0 && p1 < 0 && p2 < 0)
                p2 = 1;
            if (arr[i] == 0)
                p1 = p2 = 1;
        }
        return maxProduct;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends