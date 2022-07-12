// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    You are given an array Arr of size N. You have to find the K-th smallest sum of contiguous subarray within the array elements.
    */
    int kthLargest(vector<int> &Arr, int N, int K)
    {
        int sum;
        priority_queue<int> pq;
        for (int i = 0; i < N; i++)
        {
            sum = 0;
            for (int j = i; j < N; j++)
            {
                sum += Arr[j];
                pq.push(sum);
                if (pq.size() > K)
                    pq.pop();
            }
        }
        return pq.top();
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N, K;
        cin >> N;
        cin >> K;
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        int ans = ob.kthLargest(Arr, N, K);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends