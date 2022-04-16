// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

public:
    int countMin(string str)
    {
        // complete the function here
        vector<vector<int>> dp(str.size() + 1, vector<int>(str.size() + 1));
        for (int i = 0; i <= str.size(); i++)
        {
            for (int j = 0; j <= str.size(); j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (str[i - 1] == str[str.size() - j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return str.size() - dp[str.size()][str.size()];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}

// } Driver Code Ends