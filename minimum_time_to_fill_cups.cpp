#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fillCups(vector<int> &amount)
    {
        /*
        You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

        You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.
        */
        sort(amount.begin(), amount.end(), greater<int>());
        int count = 0;
        while (amount[0])
        {
            count++;
            amount[0]--;
            if (amount[1])
                amount[1]--;
            sort(amount.begin(), amount.end(), greater<int>());
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<int> amount(3);
        for (int i = 0; i < 3; i++)
            cin >> amount[i];

        Solution obj;
        cout << obj.fillCups(amount) << endl;
    }
    return 0;
}