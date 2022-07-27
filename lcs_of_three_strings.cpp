#include <bits/stdc++.h>
using namespace std;

int LCSof3(string A, string B, string C, int n1, int n2, int n3);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        string A, B, C;
        cin >> A >> B >> C;
        cout << LCSof3(A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    // Given 3 strings A, B and C, the task is to find the longest common sub-sequence in all three given sequences.
    vector<vector<vector<int>>> dp(A.size() + 1, vector<vector<int>>(B.size() + 1, vector<int>(C.size() + 1)));

    for (int i = 0; i <= A.size(); i++)
        for (int j = 0; j <= B.size(); j++)
            for (int k = 0; k <= C.size(); k++)
                if (i == 0 || j == 0 || k == 0)
                    dp[i][j][k] = 0;
                else if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));

    return dp[A.size()][B.size()][C.size()];
}