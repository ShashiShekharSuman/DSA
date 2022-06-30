// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int l = 0, r = nums.size();
        while (k--)
        {
            pq.push(nums[l]);
            l++;
        }
        while (l < r)
        {
            if (pq.top() < nums[l])
            {
                pq.pop();
                pq.push(nums[l]);
            }
            l++;
        }
        return pq.top();
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
        cin >> n;
        vector<int> nums(n);

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        cin >> k;
        Solution ob;
        cout << ob.findKthLargest(nums, k) << endl;
    }
    return 0;
} // } Driver Code Ends