#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    typedef pair<int, int> p;
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int meetingCount = 0, endTime = -1;
        priority_queue<p, vector<p>, greater<p>> minHeap;
        for (int i = 0; i < n; i++)
            minHeap.push({end[i], start[i]});
        while (!minHeap.empty())
        {
            if (minHeap.top().second > endTime)
            {
                meetingCount++;
                endTime = minHeap.top().first;
            }
            minHeap.pop();
        }
        return meetingCount;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} // } Driver Code Ends