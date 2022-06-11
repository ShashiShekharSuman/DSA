#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // X[], Y[]: input arrau
    // M, N: size of arrays X[] and Y[] respectively
    // Function to count number of pairs such that x^y is greater than y^x.
    long long countPairs(int X[], int Y[], int M, int N)
    {
        // Your code here
        sort(Y, Y + N);
        long long count = 0, count1 = upper_bound(Y, Y + N, 1) - lower_bound(Y, Y + N, 1);
        for (int i = 0; i < M; i++)
        {
            if (X[i] == 1)
                continue;
            else if (X[i] == 2)
                count += Y + N - upper_bound(Y, Y + N, 4) + count1;
            else if (X[i] == 3)
                count += N - (upper_bound(Y, Y + N, 3) - lower_bound(Y, Y + N, 3));
            else
                count += (Y + N - upper_bound(Y, Y + N, X[i])) + count1;
        }
        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        int i, a[M], b[N];
        for (i = 0; i < M; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < N; i++)
        {
            cin >> b[i];
        }
        Solution ob;
        cout << ob.countPairs(a, b, M, N) << endl;
    }
} // } Driver Code Ends