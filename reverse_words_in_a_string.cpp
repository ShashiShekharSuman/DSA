#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        string reverseS = "";
        vector<string> words;
        for (int i = 0; i < S.size(); i++)
        {
            int startIndex = i, wordLen = 0;
            while (i < S.size() && S[i] != '.')
            {
                i++;
                wordLen++;
            }
            words.push_back(S.substr(startIndex, wordLen));
        }
        int i = words.size() - 1;
        while (i > 0)
        {
            reverseS += words[i--];
            reverseS += '.';
        }
        reverseS += words[i];
        return reverseS;
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
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
} // } Driver Code Ends