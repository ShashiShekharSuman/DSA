/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    /*
    Given an array A[] of N integers, where A[i] denotes the height of ith tree.
    Geek needs to cut down M meters of wood. He has a woodcutting machine that works as follows:  Set the blade at a height parameter H, and the machine cuts off all trees having a height greater than H. The trees having less than height H remains intact.
    Since Geek is an environmentalist, he doesn't want to cut woods more than necessary, so he set the height H as high as possible.
    Find the maximum height H of the blade that still allows to cutoff at least M meters of wood.
    */
    int maxHeight(vector<int> &A, int M)
    {
        // Write your code here
        long long l = 0, h = *max_element(A.begin(), A.end()), mid, wood;
        while (l < h)
        {
            mid = h - (h - l) / 2;
            wood = 0;
            for (auto i : A)
                wood += max(i - mid, (long long)0);
            if (wood < M)
                h = mid - 1;
            else
                l = mid;
        }
        return h;
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
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int M;
        cin >> M;
        Solution ob;
        int ans = ob.maxHeight(A, M);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends