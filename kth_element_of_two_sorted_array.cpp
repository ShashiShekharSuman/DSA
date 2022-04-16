#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low = max(0, k - m), high = min(k, n), mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid - 1 >= 0 && mid - 1 < n &&
                k - mid >= 0 && k - mid < m &&
                arr1[mid - 1] > arr2[k - mid])
                high = mid - 1;
            else if (mid >= 0 && mid < n &&
                     k - mid - 1 >= 0 && k - mid - 1 < m &&
                     arr2[k - mid - 1] > arr1[mid])
                low = mid + 1;
            else
                break;
        }
        if (mid - 1 >= 0 && mid - 1 < n &&
            k - mid - 1 >= 0 && k - mid - 1 < m)
            return max(arr1[mid - 1], arr2[k - mid - 1]);
        else if (mid - 1 >= 0 && mid - 1 < n)
            return arr1[mid - 1];
        else
            return arr2[k - mid - 1];
    }
};
// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];

        Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
    }
    return 0;
} // } Driver Code Ends