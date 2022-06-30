#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    long long countTriplets(long long arr[], int n, long long sum)
    {
        // Your code goes here
        int triplets = 0, l, h;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            int l = i + 1, h = n - 1;
            while (l < h)
            {
                long long s = arr[i] + arr[l] + arr[h];
                if (s >= sum)
                    h--;
                else
                    triplets += h - l++;
            }
        }
        return triplets;
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
        long long sum;
        cin >> n >> sum;
        long long arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countTriplets(arr, n, sum);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends