#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i = 0, j = 0, maxLen = 0;
        unordered_map<char, int> frequency;
        while (j < s.size())
        {
            while (frequency[s[j]] > 0)
                frequency[s[i++]]--;
            frequency[s[j]]++;
            maxLen = max(maxLen, j++ - i + 1);
        }
        return maxLen;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.lengthOfLongestSubstring(s) << endl;
    }
}
