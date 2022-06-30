
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        int count = 0;
        vector<int> alphabets(26, 0);
        unordered_set<int> frequency;
        for (auto c : s)
            alphabets[c - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            while (frequency.find(alphabets[i]) != frequency.end())
            {
                count++;
                alphabets[i]--;
            }
            if (alphabets[i])
                frequency.insert(alphabets[i]);
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.minDeletions(s) << endl;
    }
    return 0;
}