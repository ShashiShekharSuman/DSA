#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<string>> perms(string S, set<string> palindromes)
    {
        vector<vector<string>> result;
        if (S == "")
            return result;
        for (auto i : palindromes)
        {
            if (i == S.substr(0, i.size()))
            {
                vector<vector<string>> temp = perms(S.substr(i.size()), palindromes);
                if (temp.size() == 0)
                    result.push_back(vector<string>(1, i));
                else
                {
                    for (int j = 0; j < temp.size(); j++)
                    {
                        temp[j].push_back(i);
                        result.push_back(temp[j]);
                    }
                }
            }
        }
        return result;
    }

    vector<vector<string>> allPalindromicPerms(string S)
    {
        // code here
        vector<vector<string>> dp(S.size(), vector<string>(S.size()));
        vector<vector<string>> result;
        set<string> palindromes;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            for (int j = i; j < S.size(); j++)
            {
                if (i == j)
                    dp[i][j] = S[i];
                else if (S[i] == S[j])
                {
                    dp[i][j] = S[j] + dp[i + 1][j - 1] + S[j];
                }
                palindromes.insert(dp[i][j]);
            }
        }
        palindromes.erase("");

        result = perms(S, palindromes);
        for (int i = 0; i < result.size(); i++)
            reverse(result[i].begin(), result[i].end());

        return result;
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
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);

        for (int i = 0; i < ptr.size(); i++)
        {
            for (int j = 0; j < ptr[i].size(); j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends