#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        vector<int> frequency(26, 0);
        for (auto i : s)
            frequency[i - 'a']++;
        for (auto i : t)
            frequency[i - 'a']--;
        for (int i = 0; i < 26; i++)
            if (frequency[i] != 0)
                return false;
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        Solution obj;
        if (obj.isAnagram(s, t))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
