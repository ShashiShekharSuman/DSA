// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    class Trie
    {
        struct Node
        {
            char data;
            Node *children[26];
            bool isEnd;
            int words;

            Node()
            {
                this->data = '*';
                this->isEnd = false;
                this->words = 0;
                for (int i = 0; i < 26; i++)
                    children[i] = NULL;
            }

            Node(char val)
            {
                this->data = val;
                this->isEnd = false;
                this->words = 0;
                for (int i = 0; i < 26; i++)
                    children[i] = NULL;
            }
        };

        Node *root;

    public:
        Trie(string arr[], int n)
        {
            this->root = new Node();
            for (int i = 0; i < n; i++)
                add(arr[i]);
        }

        void add(string &s)
        {
            int i = 0;
            Node *ptr = root;
            while (i < s.size() && ptr->children[s[i] - 'a'])
            {
                ptr->words++;
                ptr = ptr->children[s[i++] - 'a'];
            }
            while (i < s.size())
            {
                ptr->children[s[i] - 'a'] = new Node(s[i]);
                ptr->words++;
                ptr = ptr->children[s[i++] - 'a'];
            }
            ptr->isEnd = true;
        }

        void getUniquePrefix(string &s, vector<string> &prefixes)
        {
            int i = 0, j = prefixes.size();
            Node *ptr = root;
            prefixes.push_back("");
            while (i < s.size() && ptr->children[s[i] - 'a'])
            {
                ptr = ptr->children[s[i] - 'a'];
                prefixes[j] += s[i++];
                if (ptr->words == 1)
                    break;
            }
        }
    };

public:
    /*
    Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another.
    */
    vector<string> findPrefixes(string arr[], int n)
    {
        // code here
        Trie trie(arr, n);
        vector<string> prefixes;
        for (int i = 0; i < n; i++)
            trie.getUniquePrefix(arr[i], prefixes);
        return prefixes;
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
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends