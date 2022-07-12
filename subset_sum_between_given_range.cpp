/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{

    void getSubsetSums(int i, int j, vector<int> &arr, long long sum, vector<long long> &subsetSums)
    {
        if (i == j)
        {
            subsetSums.push_back(sum);
            return;
        }
        getSubsetSums(i + 1, j, arr, sum, subsetSums);
        getSubsetSums(i + 1, j, arr, sum + arr[i], subsetSums);
    }

public:
    // Given an array A[] of N integers and two integers L and R. The task is to return the total subsets of array A whose sum lies between the range [L, R], inclusive.
    long long int countSubsets(vector<int> &arr, int n, int l, int r)
    {
        // Write your code here
        long long count = 0;
        vector<long long> s1, s2;

        getSubsetSums(0, arr.size() / 2, arr, 0, s1),
            getSubsetSums(arr.size() / 2, arr.size(), arr, 0, s2);

        sort(s2.begin(), s2.end());
        for (auto sum : s1)
            count += upper_bound(s2.begin(), s2.end(), r - sum) - lower_bound(s2.begin(), s2.end(), l - sum);

        return count;
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
        int l, r;
        cin >> l >> r;
        Solution ob;
        long long int ans = ob.countSubsets(arr, n, l, r);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends