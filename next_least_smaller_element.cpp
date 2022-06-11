/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution
{
public:
    vector<int> nextLeastSmaller(vector<int> &arr, int n)
    {
        set<int> s;
        vector<int> nextLeastSmaller(n, -1);
        for (int i = n - 1; i > -1; i--)
        {
            auto it = s.lower_bound(arr[i]);
            if (it != s.begin())
                nextLeastSmaller[i] = *(--it);
            s.insert(arr[i]);
        }
        return nextLeastSmaller;
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
        vector<int> ans = ob.nextLeastSmaller(arr, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends