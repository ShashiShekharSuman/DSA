#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> maxSum(n + 1);
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
                maxSum[i] = 0;
            else if (i == 1)
                maxSum[i] = arr[i - 1];
            else
                maxSum[i] = max(arr[i - 1] + maxSum[i - 2], maxSum[i - 1]);
        }
        return maxSum[n];
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends