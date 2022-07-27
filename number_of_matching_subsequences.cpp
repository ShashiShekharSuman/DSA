#include <bits/stdc++.h>
using namespace std;

class Solution
{

    class Trie
    {
        struct Node
        {
            char data;
            Node *children[26];
            bool isEnd;
            int index;

            Node()
            {
                this->data = '*';
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
                this->index = -1;
            }

            Node(char c)
            {
                this->data = c;
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
                this->index = -1;
            }
        };

        Node *root;
        int count;

        void insert(string &word, string &s)
        {
            Node *ptr = this->root;
            int i = 0, j = -1;
            while (i < word.size() && ptr->children[word[i] - 'a'])
                ptr = ptr->children[word[i++] - 'a'];
            j = ptr->index;
            while (i < word.size())
            {
                ptr->children[word[i] - 'a'] = new Node(word[i]);
                ptr = ptr->children[word[i++] - 'a'];
                if (j == -2)
                    ptr->index = -2;
                else
                {
                    j++;
                    while (j < s.size() && s[j] != ptr->data)
                        j++;
                    if (j == s.size())
                        j = -2;
                    ptr->index = j;
                }
            }
            if (ptr->index != -2)
            {
                ptr->isEnd = true;
                this->count++;
            }
        }

    public:
        Trie(vector<string> &words, string &s)
        {
            this->root = new Node();
            this->count = 0;
            for (auto word : words)
                this->insert(word, s);
        }

        int countMatchingSubseq()
        {
            return this->count;
        }
    };

public:
    /*
    Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    */
    int numMatchingSubseq(string s, vector<string> &words)
    {
        Trie trie(words, s);
        return trie.countMatchingSubseq();
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int n;
        cin >> s >> n;
        vector<string> words;
        for (int i = 0; i < n; i++)
            cin >> words[i];
        Solution obj;
        cout << obj.numMatchingSubseq(s, words) << endl;
    }

    return 0;
}