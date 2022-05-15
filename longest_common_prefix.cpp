#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int min_str_len = INT_MAX;
        string prefix = "";
        for (int i = 0; i < strs.size(); i++)
        {
            if (strs[i].size() < min_str_len)
                min_str_len = strs[i].size();
        }
        for (int i = 0; i < min_str_len; i++)
        {
            for (int j = 1; j < strs.size(); j++)
            {
                if (strs[j][i] != strs[0][i])
                    return prefix;
            }
            prefix += strs[0][i];
        }
        return prefix;
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
        vector<string> strs(n);
        for (int i = 0; i < n; i++)
        {
            cin >> strs[i];
        }
        Solution ob;
        cout << ob.longestCommonPrefix(strs) << "\n";
    }
    return 0;
}
