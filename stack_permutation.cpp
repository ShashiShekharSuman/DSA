// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    You are given two arrays A and B of size N. Check if one array is a stack permutation of the other array or not.
    Stack permutation means that one array can be created from another array using a stack and stack operations.
    */
    int isStackPermutation(int N, vector<int> &A, vector<int> &B)
    {
        stack<int> s;
        int i = 0, j = 0;
        while (i < N)
        {
            while (i < N && A[i] != B[j])
                s.push(A[i++]);
            if (i == N)
                return 0;
            s.push(A[i++]);
            while (!s.empty() && s.top() == B[j])
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.isStackPermutation(n, a, b) << endl;
    }

    return 0;
} // } Driver Code Ends