#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int maxSubstring(string S)
    {
        // Your code goes here
        int count_0 = 0, count_1 = 0, max_diff = -1;

        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '0')
                count_0++;
            else
                count_1++;
            max_diff = max(max_diff, count_0 - count_1);
            if (count_1 > count_0)
            {
                count_1 = 0;
                count_0 = 0;
            }
        }
        return max_diff;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;

        cout << ob.maxSubstring(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends