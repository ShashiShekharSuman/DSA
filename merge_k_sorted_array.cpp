// Initial Template for C++
#include <bits/stdc++.h>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        vector<int> mergedArray;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < K; i++)
            pq.push({arr[i][0], i, 0});
        for (int i = 0; i < K * K; i++)
        {
            vector<int> top = pq.top();
            pq.pop();
            mergedArray.push_back(top[0]);
            if (top[2] < K - 1)
                pq.push({arr[top[1]][top[2] + 1], top[1], top[2] + 1});
        }
        return mergedArray;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends