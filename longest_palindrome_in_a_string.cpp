#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string S)
    {
        // code here
        string longestPalindrome = "";
        for (int i = 0; i < S.size(); i++)
        {
            for (int j = 0; i - j >= 0 && i + j < S.size(); j++)
                if (S[i - j] != S[i + j])
                    break;
                else if (longestPalindrome.size() < 2 * j + 1)
                    longestPalindrome = S.substr(i - j, 2 * j + 1);
            for (int j = 0; i - j >= 0 && i + j + 1 < S.size(); j++)
                if (S[i - j] != S[i + j + 1])
                    break;
                else if (longestPalindrome.size() < 2 * (j + 1))
                    longestPalindrome = S.substr(i - j, 2 * (j + 1));
        }
        return longestPalindrome;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends