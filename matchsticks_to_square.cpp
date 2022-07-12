#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool kPartition(vector<int> &matchsticks, int k, int i, int sum, int partition_sum, unordered_set<int> &s)
    {
        if (k == 0)
            return s.size() == matchsticks.size();
        if (sum == 0)
            return kPartition(matchsticks, k - 1, 0, partition_sum, partition_sum, s);

        for (int j = i; j < matchsticks.size(); j++)
        {
            if (s.find(j) != s.end() || sum - matchsticks[j] < 0)
                continue;
            s.insert(j);
            if (kPartition(matchsticks, k, j + 1, sum - matchsticks[j], partition_sum, s))
                return true;
            s.erase(j);
            while (j > i && matchsticks[j] == matchsticks[j - 1])
                j++;
        }
        return false;
    }

public:
    /*
    You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. You want to use all the matchsticks to make one square. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

    Return true if you can make this square and false otherwise.
    */
    bool makesquare(vector<int> &matchsticks)
    {
        long long sum = 0;
        unordered_set<int> s;
        for (auto matchstick : matchsticks)
            sum += matchstick;
        if (sum % 4 != 0)
            return false;
        sum /= 4;
        sort(matchsticks.begin(), matchsticks.end());
        return kPartition(matchsticks, 4, 0, sum, sum, s);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> matchsticks(n);
        for (int i = 0; i < n; i++)
            cin >> matchsticks[i];

        Solution obj;
        cout << obj.makesquare(matchsticks) << endl;
    }
}