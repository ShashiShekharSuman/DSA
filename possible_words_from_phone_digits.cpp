// Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void solve(int a[], int N, int index, string &word, vector<string> &adj, vector<string> &words)
    {
        if (index == N)
        {
            words.push_back(word);
            return;
        }
        for (auto letter : adj[a[index] - 2])
        {
            word += letter;
            solve(a, N, index + 1, word, adj, words);
            word.pop_back();
        }
    }

public:
    // Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        // Your code here
        string word = "";
        vector<string> adj = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, words;
        solve(a, N, 0, word, adj, words);
        return words;
    }
};

// { Driver Code Starts.

int main()
{

    int T;

    cin >> T; // testcases

    while (T--)
    { // while testcases exist
        int N;

        cin >> N; // input size of array

        int a[N]; // declare the array

        for (int i = 0; i < N; i++)
        {
            cin >> a[i]; // input the elements of array that are keys to be pressed
        }

        Solution obj;

        vector<string> res = obj.possibleWords(a, N);
        for (string i : res)
            cout << i << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends