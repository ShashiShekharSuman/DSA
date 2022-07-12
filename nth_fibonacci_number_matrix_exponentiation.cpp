#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    typedef long long ll;
    typedef vector<ll> vl;
    typedef vector<vl> vvl;
    const int mod = 1e9 + 7;

    // Matrix Multiplication
    vvl matrixMultiplication(const vvl &A, const vvl &B)
    {
        vvl C(A.size(), vl(B[0].size(), 0));
        for (int i = 0; i < A.size(); i++)
            for (int j = 0; j < B[0].size(); j++)
                for (int k = 0; k < A[0].size(); k++)
                {
                    C[i][j] += (A[i][k] * B[k][j]) % mod;
                    C[i][j] %= mod;
                }
        return C;
    }

    // Matrix Exponention
    vvl matrixExponention(const vvl &A, int n)
    {
        if (n == 0)
        {
            vvl B(A.size(), vl(A[0].size(), 0));
            for (int i = 0; i < A.size(); i++)
                B[i][i] = 1;
            return B;
        }
        if (n == 1)
            return A;
        if (n == 2)
            return matrixMultiplication(A, A);
        if (n & 1)
            return matrixMultiplication(matrixExponention(matrixExponention(A, n / 2), 2), A); // n = odd
        else
            return matrixExponention(matrixExponention(A, n / 2), 2); // n = even
    }

public:
    /*
    Given an equation of the form f(n) = f(n-1) + f(n-2) where f(0) = 1, F(1) = 1 , the task is to find the nth term of this sequence.
    */
    // nth Fibonacci number = ([[1, 1], [1, 0]] ^ (n-2)) * [[1], [1]]
    int FindNthTerm(long long int n)
    {
        // Code here
        if (n == 0)
            return 1;
        return matrixMultiplication(matrixExponention({{1, 1}, {1, 0}}, n - 1), {{1}, {1}})[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long int n;
        cin >> n;
        Solution obj;
        int ans = obj.FindNthTerm(n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends