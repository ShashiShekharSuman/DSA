#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    Given an array Arr[] of size N and an integer K, you have to add the first two minimum elements of the array until all the elements are greater than or equal to K and find the number of such operations required.
    */
    int minOperations(int arr[], int n, int k)
    {
        // code here
        int moves = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
            pq.push(arr[i]);
        while (!pq.empty() && pq.top() < k)
        {
            int top = pq.top();
            pq.pop();
            if (!pq.empty())
            {
                pq.push(top + pq.top());
                pq.pop();
                moves++;
            }
            else
                return -1;
        }
        return moves;
    }
};

//{ Driver Code Starts.
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
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends