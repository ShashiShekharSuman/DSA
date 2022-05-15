#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (('z' < s[i] || s[i] < 'a') && ('9' < s[i] || s[i] < '0'))
                i++;
            else if (('z' < s[j] || s[j] < 'a') && ('9' < s[j] || s[j] < '0'))
                j--;
            else if (s[i++] != s[j--])
                return false;
        }
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
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.isPalindrome(s))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}
