#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
    You are giving candies to these children subjected to the following requirements:
        > Each child must have at least one candy.
        > Children with a higher rating get more candies than their neighbors.
    Return the minimum number of candies you need to have to distribute the candies to the children.
    */
    int candy(vector<int> &ratings)
    {
        vector<int> dp(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
            if (ratings[i] > ratings[i - 1])
                dp[i] = dp[i - 1] + 1;
        int candies = dp[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
                dp[i] = max(dp[i], dp[i + 1] + 1);
            candies += dp[i];
        }
        return candies;
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
        vector<int> ratings(n);

        for (int i = 0; i < n; i++)
            cin >> ratings[i];

        Solution obj;
        cout << obj.candy(ratings) << "\n";
    }
    return 0;
}