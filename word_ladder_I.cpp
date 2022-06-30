#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
    {
        // Code here
        int count = 1, deviation;
        vector<bool> visited(wordList.size(), false);
        queue<string> q;
        q.push(startWord);
        q.push("-1");
        while (!q.empty())
        {
            if (q.front() == "-1")
            {
                q.pop();
                count++;
                if (!q.empty())
                    q.push("-1");
            }
            else
            {
                for (int i = 0; i < wordList.size(); i++)
                {
                    if (visited[i])
                        continue;
                    deviation = 0;
                    for (int j = 0; j < wordList[i].size(); j++)
                    {
                        if (wordList[i][j] != q.front()[j])
                            deviation++;
                        if (deviation > 1)
                            break;
                    }
                    if (deviation > 1)
                        continue;
                    if (wordList[i] == targetWord)
                        return count + 1;
                    q.push(wordList[i]);
                    visited[i] = true;
                }
                q.pop();
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++)
            cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        int ans = obj.wordLadderLength(startWord, targetWord, wordList);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends