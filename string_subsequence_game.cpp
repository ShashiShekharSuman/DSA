// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    void solve(string &S, int i, string &word, set<string> &s)
    {
        if (word.size() > 1 && isVowel(word[0]) && !isVowel(word.back()))
            s.insert(word);

        while (i < S.size())
        {
            word += S[i++];
            solve(S, i, word, s);
            word.pop_back();
        }
    }

public:
    /*
    Given a string return all unique possible subsequences which start with vowel and end with consonant. A String is a subsequence of a given String, that is generated by deleting some character of a given string without changing its order.
    NOTE: Return all the unique subsequences in lexicographically sorted order.
    */
    set<string> allPossibleSubsequences(string S)
    {
        // code here
        string word = "";
        set<string> s;
        solve(S, 0, word, s);
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else
        {
            for (auto i : ans)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends