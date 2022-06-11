#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        int a = 1, b = 0, c = 0;
        for (int i = 1; i <= n; i++)
        {
            c = i > 1 ? a + b : a;
            b = a;
            a = c;
        }
        return c;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.climbStairs(n) << endl;
    }
    return 0;
} // } Driver Code Ends