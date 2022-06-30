#include <bits/stdc++.h>
using namespace std;

class WordFilter
{
    unordered_map<string, int> m;

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            int len = words[i].size();
            string prefix_suffix = "";
            for (int j = 0; j < len; j++)
            {
                prefix_suffix += words[i][j];
                prefix_suffix += ' ';
                for (int k = 0; k < len; k++)
                {
                    prefix_suffix += words[i].substr(len - k - 1);
                    m[prefix_suffix] = i;
                    prefix_suffix.erase(prefix_suffix.begin() + j + 2, prefix_suffix.end());
                }
                prefix_suffix.pop_back();
            }
        }
    }

    int f(string prefix, string suffix)
    {
        prefix += ' ';
        prefix += suffix;
        if (m.find(prefix) != m.end())
            return m[prefix];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n, q;
        vector<string> words(n);
        for (int i = 0; i < n; i++)
            cin >> words[i];
        WordFilter *obj = new WordFilter(words);
        for (int i = 0; i < q; i++)
        {
            string prefix, suffix;
            cin >> prefix >> suffix;
            cout << obj->f(prefix, suffix) << " ";
        }
        cout << "\n";
    }
    return 0;
}