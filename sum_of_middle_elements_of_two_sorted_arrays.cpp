// Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int findMidSum(int ar1[], int ar2[], int n)
    {
        // code here
        int low = 0, high = n, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid - 1 >= 0 && mid - 1 < n &&
                n - mid >= 0 && n - mid < n &&
                ar1[mid - 1] > ar2[n - mid])
                high = mid - 1;
            else if (mid >= 0 && mid < n &&
                     n - mid - 1 >= 0 && n - mid - 1 < n &&
                     ar2[n - mid - 1] > ar1[mid])
                low = mid + 1;
            else
                break;
        }
        return min(mid >= 0 && mid < n ? ar1[mid] : INT_MAX,
                   n - mid >= 0 && n - mid < n ? ar2[n - mid] : INT_MAX) +
               max(mid - 1 >= 0 && mid - 1 < n ? ar1[mid - 1] : INT_MIN,
                   n - mid - 1 >= 0 && n - mid - 1 < n ? ar2[n - mid - 1] : INT_MIN);
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
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++)
        {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends