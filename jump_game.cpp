// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int canReach(int A[], int N)
    {
        // code here
        int i = 0, steps = 1;
        while (i < N && steps)
        {
            if (i == N - 1)
                return 1;
            steps = max(steps - 1, A[i++]);
        }
        return 0;
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

        int A[N];

        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.canReach(A, N) << endl;
    }
    return 0;
} // } Driver Code Ends