// Initial template for C++

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
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
                this->words = 0;
            }

            Node(char val)
            {
                this->data = val;
                for (int i = 0; i < 26; i++)
                    this->children[i] = NULL;
                this->isEnd = false;
                this->words = 0;
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
            int i = s.size() - 1;
            Node *ptr = root;
            while (i >= 0 && ptr->children[s[i] - 'a'])
                ptr = ptr->children[s[i--] - 'a'];
            while (i >= 0)
            {
                ptr->children[s[i] - 'a'] = new Node(s[i]);
                ptr->words++;
                ptr = ptr->children[s[i--] - 'a'];
            }
            ptr->isEnd = true;
            ptr->words++;
        }

        bool search(string &s, int i, int j)
        {
            Node *ptr = root;
            while (i < j && ptr->children[s[i] - 'a'])
                ptr = ptr->children[s[i++] - 'a'];
            return i == j && ptr->isEnd == true;
        }

        int occurance(string &s)
        {
            int i = 0, count = 0;
            Node *ptr = root;
            while (i < s.size() && ptr->children[s[i] - 'a'])
                ptr = ptr->children[s[i++] - 'a'];
            if (i != s.size() || ptr->isEnd == false)
                return 0;
            count += ptr->words;
            for (i = 0; i < 26; i++)
                if (ptr->children[i])
                    count -= ptr->children[i]->words;
            return count;
        }
    };

    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

public:
    /*
    Given an array of strings arr[] of size N, find if there exists 2 strings arr[i] and arr[j] such that arr[i] + arr[j] is a palindrome i.e the concatenation of string arr[i] and arr[j] results into a palindrome.
    */
    bool palindromepair(int N, string arr[])
    {
        // code here
        Trie trie(arr, N);
        bool palindrome;
        int occurances;
        for (int i = 0; i < N; i++)
        {
            palindrome = isPalindrome(arr[i], 0, arr[i].size() - 1);
            occurances = trie.occurance(arr[i]);
            if ((palindrome && occurances > 1) || (!palindrome && occurances))
                return true;
            for (int j = 0; j < arr[i].size(); j++)
            {
                if (trie.search(arr[i], 0, j) && isPalindrome(arr[i], j, arr[i].size() - 1))
                    return true;
                if (isPalindrome(arr[i], 0, j) && trie.search(arr[i], j + 1, arr[i].size()))
                    return true;
            }
        }
        return false;
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
        string arr[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends