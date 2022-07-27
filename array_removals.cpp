// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    Given an array arr[] of size N and an integer K. The task is to find the minimum number of elements that should be removed, such that Amax-Amin<=K. After the removal of elements, Amax and Amin is considered among the remaining elements.
    */
    int removals(vector<int> &a, int k)
    {
        // Code here
        sort(a.begin(), a.end());
        int i = 0, j = 0, n = a.size(), removals = n;
        while (j < n)
        {
            while (j < n && a[j] - a[i] <= k)
                j++;
            removals = min(removals, n - (j - i));
            i++;
        }
        return removals;
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        int ans = ob.removals(a, k);

        cout << ans << endl;
    }
}

// } Driver Code Ends