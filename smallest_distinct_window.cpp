#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findSubString(string str)
    {
        // Your code goes here
        int minWindow = str.size();
        unordered_set<char> s(str.begin(), str.end());
        unordered_map<char, int> m;
        int i = 0, j = 0;
        while (j < str.size())
        {
            m[str[j]]++;
            while (i <= j && m.size() == s.size())
            {
                minWindow = min(minWindow, j - i + 1);
                if (--m[str[i]] == 0)
                    m.erase(str[i]);
                i++;
            }
            j++;
        }
        return minWindow;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
} // } Driver Code Ends