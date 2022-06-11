// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxCoins(int A[], int B[], int T, int N)
    {
        // code here
        vector<pair<int, int>> C;
        int minCoins = 0;
        for (int i = 0; i < N; i++)
            C.push_back({B[i], A[i]});
        sort(C.begin(), C.end(), greater<pair<int, int>>());
        for (int i = 0; i < N && T > 0; i++)
        {
            minCoins += min(T, C[i].second) * C[i].first;
            T -= min(T, C[i].second);
        }
        return minCoins;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int T, N;
        cin >> T >> N;

        int A[N], B[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];

        Solution ob;
        cout << ob.maxCoins(A, B, T, N) << endl;
    }
    return 0;
} // } Driver Code Ends