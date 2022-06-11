// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Complet the function
        int window = 0, minSwaps, swaps = 0;
        for (int i = 0; i < n; i++)
            if (arr[i] <= k)
                window++;
        int i = 0, j = 0;
        while (j < window)
            if (arr[j++] > k)
                swaps++;
        minSwaps = swaps;
        while (j < n)
        {
            if (arr[j++] > k)
                swaps++;
            if (arr[i++] > k)
                swaps--;
            minSwaps = min(minSwaps, swaps);
        }
        return minSwaps;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cin >> k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends