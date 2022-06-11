// Driver Code
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
// Complete this function
long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1; // If 0 sum is required number of ways is 1.

    // Your code here
    int x;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
            x = 3;
        else if (i == 1)
            x = 5;
        else
            x = 10;
        for (int i = 1; i <= n; i++)
        {
            if (i - x > -1)
                table[i] += table[i - x];
        }
    }

    return table[n];
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << count(n) << endl;
    }
    return 0;
} // } Driver Code Ends