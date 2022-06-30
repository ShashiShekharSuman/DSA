
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void partition(string &s, int index, unordered_set<string> &words, string &sentance, vector<string> &sentances)
    {
        if (index == s.size())
        {
            sentance.pop_back();
            sentances.push_back(sentance);
            sentance += ' ';
            return;
        }
        string word = "";
        while (index < s.size())
        {
            word += s[index++];
            while (index < s.size() && words.find(word) == words.end())
                word += s[index++];
            if (words.find(word) == words.end())
                continue;
            sentance += word;
            sentance += ' ';
            partition(s, index, words, sentance, sentances);
            sentance.resize(sentance.size() - word.size() - 1);
        }
    }

public:
    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        // code here
        unordered_set<string> words(dict.begin(), dict.end());
        string sentance = "";
        vector<string> sentances;
        partition(s, 0, words, sentance, sentances);
        return sentances;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends