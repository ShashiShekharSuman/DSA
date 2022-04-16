#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool sumPair(int A[], int n, int sum, int index)
    {
        int i = 0, j = n - 1;
        while (i < j)
        {
            if (i == index || A[i] + A[j] < sum)
                i++;
            else if (j == index || A[i] + A[j] > sum)
                j--;
            else
                return true;
        }
        return false;
    }

    bool find3Numbers(int A[], int n, int X)
    {
        // Your Code Here
        sort(A, A + n);
        for (int i = 0; i < n; i++)
            if (sumPair(A, n, X - A[i], i))
                return true;

        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}
// } Driver Code Ends