#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
public:
    /*
    Given an array arr[] of N positive integers. Find an integer denoting the maximum XOR subset value in the given array arr[].
    */
    int maxSubarrayXOR(int arr[], int N)
    {
        // Your code here
        if (N == 0)
            return 0;
        int x = 0, maxElement = *max_element(arr, arr + N);
        ;
        while (maxElement)
        {
            x = max(x, x ^ maxElement);
            for (int i = 0; i < N; i++)
                arr[i] = min(arr[i], arr[i] ^ maxElement);
            maxElement = *max_element(arr, arr + N);
        }
        return x;
    }
};

// { Driver Code Starts.
int main()
{

    int t, n, a[100004], k;
    scanf("%d", &t);
    while (t--)
    {
        // cin>>n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        Solution obj;
        printf("%d\n", obj.maxSubarrayXOR(a, n));
        // cout<<bin(a,0,n-1,k)<<endl;
    }
} // } Driver Code Ends