// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

public:
    string remove(string s)
    {
        // code here
        string str = "";
        // int i = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i - 1 >= 0 && s[i] == s[i - 1])
                continue;
            if (i + 1 < s.size() && s[i] == s[i + 1])
                continue;
            str += s[i];
        }
        // cout<<str<<endl;
        if (str.size() == s.size())
            return str;
        return remove(str);
    }
};
// abccbccba
// { Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
} // } Driver Code Ends