#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int trailingZeros(int n)
    {
        int zeros = 0;
        for (int i = 5; i <= n; i *= 5)
            zeros += n / i;
        return zeros;
    }

public:
    int findNum(int n)
    {
        int low = 0, high = 5 * n, mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (n <= trailingZeros(mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
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
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends