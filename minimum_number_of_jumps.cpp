#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        if (n == 1)
            return 0;
        int jump = 0, range = 0, position = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > position)
                return -1;
            if (i + arr[i] > position)
                position = i + arr[i];
            if (position >= n - 1)
                return jump + 1;
            if (i == range)
            {
                jump++;
                range = position;
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends