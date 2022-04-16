// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        // code here

        sort(arr, arr + n);
        int small = arr[0];
        int large = arr[n - 1];
        int minDiff = large - small;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < k)
                continue;
            minDiff = min(minDiff, max(arr[i - 1] + k, large - k) - min(small + k, arr[i] - k));
        }
        return minDiff;
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
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends