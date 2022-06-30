// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template

class Solution
{
public:
    // s : given string
    // return the expected answer
    int fun(string &s)
    {
        // code here
        long long mod = 1e9 + 7, a = 0, ab = 0, abc = 0;
        for (auto &c : s)
            if (c == 'a')
            {
                a += a + 1;
                a %= mod;
            }
            else if (c == 'b')
            {
                ab += ab + a;
                ab %= mod;
            }
            else
            {
                abc += abc + ab;
                abc %= mod;
            }
        return abc;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.fun(s) << endl;
    }
    return 0;
} // } Driver Code Ends