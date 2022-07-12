#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given the strings key and message, which represent a cipher key and a secret message, respectively. The steps to decode message are as follows:

        1. Use the first appearance of all 26 lowercase English letters in key as the order of the substitution table.
        2. Align the substitution table with the regular English alphabet.
        3. Each letter in message is then substituted using the table.
        4. Spaces ' ' are transformed to themselves.

    For example, given key = "happy boy" (actual key would have at least one instance of each letter in the alphabet), we have the partial substitution table of ('h' -> 'a', 'a' -> 'b', 'p' -> 'c', 'y' -> 'd', 'b' -> 'e', 'o' -> 'f').

    Return the decoded message.
    */
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> m;
        int i = 0, j = 0;
        while (i < key.size() && j < 26)
        {
            if (key[i] == ' ')
            {
                i++;
                continue;
            }
            if (m.find(key[i]) == m.end())
                m[key[i]] = (char)(j++ + 'a');
            i++;
        }
        for (int k = 0; k < message.size(); k++)
        {
            if (message[k] == ' ')
                continue;
            message[k] = m[message[k]];
        }
        return message;
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string key, message;
        getline(cin, key);
        getline(cin, message);
        Solution obj;
        cout << obj.decodeMessage(key, message) << "\n";
    }
    return 0;
}