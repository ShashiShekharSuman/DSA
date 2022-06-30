
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Solution
{
    void assign(int i, vector<int> &jobs, int k, vector<ll> &dp, ll &minTime, ll time)
    {
        if (time >= minTime)
            return;

        if (i == jobs.size())
        {
            minTime = time;
            return;
        }

        for (int j = 0; j < min(i + 1, k); j++)
        {
            if (j > 0 && dp[j] == dp[j - 1])
                continue;
            dp[j] += jobs[i];
            assign(i + 1, jobs, k, dp, minTime, max(time, dp[j]));
            dp[j] -= jobs[i];
        }
    }

public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        ll minTime = INT_MAX;
        vector<ll> dp(k, 0);
        assign(0, jobs, k, dp, minTime, 0);
        return minTime;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        vector<int> jobs;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> jobs[i];
        cin >> k;
        Solution obj;
        cout << obj.minimumTimeRequired(jobs, k) << endl;
    }
    return 0;
}