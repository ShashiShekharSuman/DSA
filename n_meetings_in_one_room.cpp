// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) where S[i] is the start time of meeting i and F[i] is the finish time of meeting i. The task is to find the maximum number of meetings that can be accommodated in the meeting room. You can accommodate a meeting if the start time of the meeting is strictly greater than the finish time of the previous meeting. Print all meeting numbers.

    Note: If two meetings can be chosen for the same slot then choose meeting with smaller start time.
    */
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<vector<int>> meetings;
        for (int i = 0; i < N; i++)
            meetings.push_back({F[i], S[i], i + 1});
        vector<int> result;
        sort(meetings.begin(), meetings.end(), [](const vector<int> &v1, const vector<int> &v2)
             { return (v1[0] == v2[0] ? v1[2] < v2[2] : v1[0] < v2[0]); });
        int end = -1;
        for (int i = 0; i < N; i++)
        {
            if (meetings[i][1] > end && meetings[i][0] >= meetings[i][1])
            {
                result.push_back(meetings[i][2]);
                end = meetings[i][0];
            }
        }
        sort(result.begin(), result.end());
        return result;
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
        vector<int> S(n), F(n);
        for (int i = 0; i < n; i++)
        {
            cin >> S[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> F[i];
        }
        Solution ob;
        vector<int> ans = ob.maxMeetings(n, S, F);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if (i != ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends