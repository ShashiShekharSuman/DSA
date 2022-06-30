#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

class Solution
{
    void distribute(int i, vector<int> &cookies, vector<ll> &dp, ll &unfairness)
    {
        if (i == cookies.size())
        {
            ll mx = dp[0];
            for (int j = 1; j < dp.size(); j++)
                mx = max(mx, dp[j]);
            unfairness = min(unfairness, mx);
            return;
        }
        for (int j = 0; j < dp.size(); j++)
        {
            dp[j] += cookies[i];
            distribute(i + 1, cookies, dp, unfairness);
            dp[j] -= cookies[i];
        }
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        ll unfairness = INT_MAX;
        vector<ll> dp(k, 0);
        distribute(0, cookies, dp, unfairness);
        return unfairness;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        vector<int> cookies;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> cookies[i];
        cin >> k;
        Solution obj;
        cout << obj.distributeCookies(cookies, k) << endl;
    }
    return 0;
}