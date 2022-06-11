#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string rearrangeString(string str)
    {
        // code here
        vector<int> frequency(26, 0);
        for (auto i : str)
            frequency[i - 'a']++;
        int i = 0, j = 0;
        while (i < str.size())
        {
            while (frequency[j] == 0)
            {
                j++;
                j %= 26;
            }
            str[i] = (char)(j++ + 'a');
            j %= 26;
            if (i > 0 && str[i] == str[i - 1])
                return "-1";
            i++;
        }
        // cout << str << endl;
        return str;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution obj;
    cout << obj.rearrangeString(s) << endl;
    return 0;
}