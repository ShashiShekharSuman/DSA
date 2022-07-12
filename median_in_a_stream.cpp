#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
class Solution
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Function to insert heap.
    void insertHeap(int &x)
    {
        if (minHeap.empty() || x >= minHeap.top())
            minHeap.push(x);
        else
            maxHeap.push(x);
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        int m = maxHeap.size(), n = minHeap.size();
        while (n - m > 1)
        {
            maxHeap.push(minHeap.top());
            m++;
            minHeap.pop();
            n--;
        }
        while (m > n)
        {
            minHeap.push(maxHeap.top());
            n++;
            maxHeap.pop();
            m--;
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (minHeap.empty())
            return 0;
        if (maxHeap.size() == minHeap.size())
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2;
        return minHeap.top();
    }
};

// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
} // } Driver Code Ends