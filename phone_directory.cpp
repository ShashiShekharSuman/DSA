// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    struct Trie
    {
        struct Node
        {
            char data;
            Node *children[26];
            bool isEnd;

            Node()
            {
                this->data = '*';
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
            }

            Node(char data)
            {
                this->data = data;
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
            }
        };

        Node *root;

        Trie(int n, string contact[])
        {
            this->root = new Node();
            for (int i = 0; i < n; i++)
                this->insert(contact[i]);
        }

        void insert(string &s)
        {
            Node *node = root;
            int i = 0;
            while (i < s.size() && node->children[s[i] - 'a'])
                node = node->children[s[i++] - 'a'];
            while (i < s.size())
            {
                node->children[s[i] - 'a'] = new Node(s[i]);
                node = node->children[s[i++] - 'a'];
            }
            node->isEnd = true;
        }

        vector<string> search(string &s)
        {
            Node *node = root;
            int i = 0;
            while (i < s.size() && node->children[s[i] - 'a'])
                node = node->children[s[i++] - 'a'];
            if (i < s.size())
                return {"0"};
            vector<string> result;
            traverse(node, s, result);
            return result;
        }

        void traverse(Node *node, string &str, vector<string> &result)
        {
            if (node->isEnd)
                result.push_back(str);
            for (int i = 0; i < 26; i++)
                if (node->children[i])
                {
                    str += (char)(i + 'a');
                    traverse(node->children[i], str, result);
                    str.pop_back();
                }
        }
    };

public:
    /*
    Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order.
    Note: If there is no match between query and contacts, print "0".
    */
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        Trie contacts(n, contact);
        string search_query = "";
        vector<vector<string>> result;
        for (auto c : s)
        {
            search_query += c;
            result.push_back(contacts.search(search_query));
        }
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
        int n;
        cin >> n;
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
} // } Driver Code Ends