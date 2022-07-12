/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    bool isPossible(vector<int> &A, int N, int limit)
    {
        int i = 0, t = 0, j = 1;
        while (N--)
        {
            while (i < A.size() && t + A[i] * j > limit)
            {
                i++;
                j = 1;
                t = 0;
            }
            if (i == A.size())
                return false;
            t += A[i] * j++;
        }
        return true;
    }

public:
    /*
    Geek is organizing a party at his house. For the party, he needs exactly N donuts for the guests. Geek decides to order the donuts from a nearby restaurant, which has L chefs and each chef has a rank R.
    A chef with rank R can make 1 donut in the first R minutes, 1 more donut in the next 2R minutes, 1 more donut in 3R minutes, and so on.
    For example. a chef with rank 2, can make one donut in 2 minutes, one more donut in the next 4 minutes, and one more in the next 6 minutes. So, it take 2 + 4 + 6 = 12 minutes to make 3 donuts. A chef can move on to making the next donut only after completing the previous one. All the chefs can work simultaneously.
    Since, it's time for the party, Geek wants to know the minimum time required in completing N donuts. Return an integer denoting the minimum time
    */
    int findMinTime(int N, vector<int> &A, int L)
    {
        // write your code here
        sort(A.begin(), A.end());
        int low = 0, high = (N * (N + 1) / 2) * A[0], mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (isPossible(A, N, mid))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
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
        int l;
        cin >> l;
        vector<int> arr(l);
        for (int i = 0; i < l; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        int ans = ob.findMinTime(n, arr, l);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends