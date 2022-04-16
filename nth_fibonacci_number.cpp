// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int nthFibonacci(long long int n)
    {
        // code here
        long long int a = 1, b = -1, c;
        while (1 + n--)
        {
            c = (a + b) % (long long)(1e9 + 7);
            b = a;
            a = c;
        }
        return c;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
// } Driver Code Ends