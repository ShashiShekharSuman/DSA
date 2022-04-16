#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea = 0;
        vector<int> next_index(n, n), prev_index(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                next_index[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                prev_index[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < n; i++)
            if (arr[i] * (next_index[i] - prev_index[i] - 1) > maxArea)
                maxArea = arr[i] * (next_index[i] - prev_index[i] - 1);

        return maxArea;
    }
};

// { Driver Code Starts.

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends