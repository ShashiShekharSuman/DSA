#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void find(const string &S, string &permutation, vector<string> &permutations)
    {
        if (S.size() == 0)
        {
            permutations.push_back(permutation);
            return;
        }
        for (int i = 0; i < S.size(); i++)
        {
            permutation += S[i];
            find(S.substr(0, i) + S.substr(i + 1, S.length() - i - 1), permutation, permutations);
            permutation.pop_back();
        }
    }

public:
    vector<string> find_permutation(string S)
    {
        // Code here there
        sort(S.begin(), S.end());
        vector<string> permutations;
        string permutation = "";
        find(S, permutation, permutations);
        return permutations;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends