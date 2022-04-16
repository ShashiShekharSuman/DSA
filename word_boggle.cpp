// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1},
        dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};

    bool isValid(int i, int j, int N, int M)
    {
        return i >= 0 && j >= 0 && i < N && j < M;
    }

    void dfs(int i, int j, int N, int M, int index, string &word, vector<string> &words,
             unordered_set<string> &f, vector<vector<char>> &board, vector<vector<bool>> &visited)
    {

        if (f.find(word) != f.end())
            return;
        if (index == word.size())
        {
            words.push_back(word);
            f.insert(word);
            return;
        }
        visited[i][j] = true;
        for (int k = 0; k < 8; k++)
        {
            if (!isValid(i + dx[k], j + dy[k], N, M))
                continue;
            if (visited[i + dx[k]][j + dy[k]])
                continue;
            if (board[i + dx[k]][j + dy[k]] != word[index])
                continue;
            dfs(i + dx[k], j + dy[k], N, M, index + 1, word, words, f, board, visited);
        }
        visited[i][j] = false;
    }

public:
    vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
    {
        // Code here
        int N = board.size(),
            M = board[0].size();
        vector<string> words;
        map<char, vector<string>> start;
        unordered_set<string> found;
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        for (auto i : dictionary)
            start[i[0]].push_back(i);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (start.find(board[i][j]) == start.end())
                    continue;
                for (auto word : start[board[i][j]])
                {
                    dfs(i, j, N, M, 1, word, words, found, board, visited);
                }
            }
        }
        return words;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i)
        {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }

        int R, C;
        cin >> R >> C;
        vector<vector<char>> board(R);
        for (int i = 0; i < R; i++)
        {
            board[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else
        {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++)
                cout << output[i] << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends