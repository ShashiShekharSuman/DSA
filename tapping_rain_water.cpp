#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{

    // Function to find the trapped water between the blocks.
public:
    vector<int> nextLargest(int arr[], int n)
    {
        vector<int> next(n, -1);

        for (int i = n - 2; i >= 0; i--)
            if (arr[i] < max(arr[i + 1], next[i + 1]))
                next[i] = max(arr[i + 1], next[i + 1]);

        return next;
    }

    vector<int> prevLargest(int arr[], int n)
    {
        vector<int> prev(n, -1);

        for (int i = 1; i < n; i++)
            if (arr[i] < max(arr[i - 1], prev[i - 1]))
                prev[i] = max(arr[i - 1], prev[i - 1]);

        return prev;
    }

    long long trappingWater(int arr[], int n)
    {
        // code here
        vector<int> next = nextLargest(arr, n),
                    prev = prevLargest(arr, n);

        long long trapedWater = 0;
        for (int i = 0; i < n; i++)
        {
            if (min(next[i], prev[i]) > 0)
                trapedWater += min(next[i], prev[i]) - arr[i];
        }
        return trapedWater;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;

        int a[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        // calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends