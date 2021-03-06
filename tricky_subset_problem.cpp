// Initial Template for C+
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
        long long sum = S;
        vector<long long> numbers;
        numbers.push_back(S);
        for (long long i = 0; i < N; i++)
        {
            if (sum + A[i] == X)
                return 1;
            if (sum + A[i] > X)
                break;
            numbers.push_back(sum + A[i]);
            sum += sum + A[i];
        }
        for (long long i = numbers.size() - 1; i >= 0; i--)
        {
            if (X >= numbers[i])
                X -= numbers[i];
            if (X == 0)
                return 1;
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
        long long S, N, X;
        cin >> S >> N >> X;
        long long A[N];
        for (long long i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        if (ob.isPossible(S, N, X, A))
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
} // } Driver Code Ends