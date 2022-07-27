// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    Given an array arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the minimum sum and return its sum.
    */
    int smallestSumSubarray(vector<int> &a)
    {
        // Code here
        int sum = -a[0], minSum = -a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (sum < 0)
                sum = 0;
            sum += -a[i];
            minSum = max(sum, minSum);
        }
        return -minSum;
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

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;
    }
} // } Driver Code Ends