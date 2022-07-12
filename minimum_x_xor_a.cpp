// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    // count set bits
    int countSetBits(int n)
    {
        int setBits = 0;
        while (n)
        {
            setBits += n & 1;
            n >>= 1;
        }
        return setBits;
    }

public:
    /*
    Given two integers A and B, the task is to find an integer X such that (X XOR A) is minimum possible and the count of set bit in X is equal to the count of set bits in B.
    */
    int minVal(int a, int b)
    {
        // code here
        int setBits_a = countSetBits(a),
            setBits_b = countSetBits(b),
            flips = setBits_a - setBits_b;

        while (flips > 0)
        {
            a &= (a - 1); // unset right most set bit
            flips--;
        }

        while (flips < 0)
        {
            a = ~(~a & (~a - 1)); // set right most unset bit
            flips++;
        }

        return a;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
} // } Driver Code Ends