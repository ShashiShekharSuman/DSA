// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    bool isValid(int c, int n)
    {
        return c >= 0 && c < n;
    }

public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int n = Matrix.size(), maxSum = Matrix[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int m = Matrix[i - 1][j];
                if (isValid(j - 1, n))
                    m = max(m, Matrix[i - 1][j - 1]);
                if (isValid(j + 1, n))
                    m = max(m, Matrix[i - 1][j + 1]);
                Matrix[i][j] += m;
                maxSum = max(maxSum, Matrix[i][j]);
            }
        }
        return maxSum;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends