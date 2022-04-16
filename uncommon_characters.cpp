#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string UncommonChars(string A, string B)
    {
        // code here
        string uncommon = "";
        vector<int> charsA(26, 0);
        vector<int> charsB(26, 0);
        // int n = max(A.size(), B.size());
        for (int i = 0; i < A.size(); i++)
        {
            charsA[A[i] - 'a'] = 1;
            charsB[A[i] - 'a'] = -1;
        }
        for (int i = 0; i < B.size(); i++)
        {
            charsB[B[i] - 'a'] = 1;
            if (charsA[B[i] - 'a'] != 1)
                charsA[B[i] - 'a'] = -1;
        }
        for (int i = 0; i < 26; i++)
            if (charsA[i] == -1 || charsB[i] == -1)
                uncommon += (char)(i + 'a');

        if (uncommon.size() > 0)
            return uncommon;
        return "-1";
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends