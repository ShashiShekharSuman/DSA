/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    vector<int> prevLeastSmaller(vector<int> &arr, int n)
    {
        set<int> s;
        vector<int> prevLeastSmaller(n, -1);
        for (int i = 0; i < n; i++)
        {
            auto it = s.lower_bound(arr[i]);
            if (it != s.begin())
                prevLeastSmaller[i] = *(--it);
            s.insert(arr[i]);
        }
        return prevLeastSmaller;
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
        Solution ob;
        vector<int> ans = ob.prevLeastSmaller(arr, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends