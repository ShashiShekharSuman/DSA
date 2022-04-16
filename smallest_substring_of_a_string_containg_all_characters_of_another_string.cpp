#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the smallest window in the string s consisting
    // of all the characters of string p.
    string smallestWindow(string s, string p)
    {
        // Your code here
        unordered_map<char, int> m;
        for (int i = 0; i < p.size(); i++)
            m[p[i]]++;
        int count = m.size(), i = 0, j = 0, n = s.size(), start, len = s.size();
        while (j < n)
        {
            if (m.find(s[j]) != m.end())
            {
                m[s[j]]--;
                if (m[s[j]] == 0)
                    count--;
            }
            while (count == 0)
            {
                if (len > j - i + 1)
                {
                    len = j - i + 1;
                    start = i;
                }
                if (m.find(s[i]) != m.end())
                {
                    m[s[i]]++;
                    if (m[s[i]] == 1)
                        count++;
                }
                i++;
            }
            j++;
        }
        return len == s.size() ? "-1" : s.substr(start, len);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends