#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        // code here
        int *pair = new int[2];
        for (int i = 0; i < n; i++)
        {
            while (arr[i] != arr[arr[i] - 1])
                swap(arr[i], arr[arr[i] - 1]);
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                pair[0] = arr[i];
                pair[1] = i + 1;
            }
        }
        return pair;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends