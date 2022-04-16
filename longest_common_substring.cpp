#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // your code here
        int max_len = 0;
        for (int k = 0; k < n; k++)
        {
            int i = k, j = 0, len = 0;
            while (i < n && j < m)
            {
                if (S1[i++] == S2[j++])
                    len++;
                else
                    len = 0;
                max_len = max(len, max_len);
            }
        }

        for (int k = 1; k < m; k++)
        {
            int i = 0, j = k, len = 0;
            while (i < n && j < m)
            {
                if (S1[i++] == S2[j++])
                    len++;
                else
                    len = 0;
                max_len = max(len, max_len);
            }
        }

        return max_len;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends