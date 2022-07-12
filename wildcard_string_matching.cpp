#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    /*
    Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

    * --> This character in string wild can be replaced by any sequence of characters, it can also be replaced by an empty string.
    ? --> This character in string wild can be replaced by any one character
    */
    bool match(string wild, string pattern)
    {
        // code here
        if (wild == pattern)
            return true;
        int i = 0, j = 0;
        while (i < wild.size() && j < pattern.size())
        {
            if (wild[i] == pattern[j] || wild[i] == '?')
            {
                i++;
                j++;
            }
            else if (wild[i] == '*')
            {
                wild = wild.substr(i + 1);
                while (j <= pattern.size())
                {
                    if (match(wild, pattern.substr(j++)))
                        return true;
                }
            }
            else
                return false;
        }

        // checking ending starts
        if (i < wild.size())
        {
            while (i < wild.size())
                if (wild[i++] != '*')
                    return false;
            return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends