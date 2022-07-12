#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    You must write an algorithm that runs in O(n) time.
    */

    // arr[] : the input array
    // N : size of the array arr[]
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        int maxLen = 0;
        unordered_set<int> s(arr, arr + N);
        for (int i = 0; i < N; i++)
        {
            if (s.find(arr[i] - 1) == s.end())
            {
                int j = 0;
                while (s.find(j + arr[i]) != s.end())
                    j++;
                maxLen = max(j, maxLen);
            }
        }
        return maxLen;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends