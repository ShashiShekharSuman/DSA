#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        // code here
        priority_queue<int> pq;
        vector<int> kLarge;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        int i = 0;
        while (i < k)
        {
            kLarge.push_back(pq.top());
            pq.pop();
            i++;
        }
        return kLarge;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends