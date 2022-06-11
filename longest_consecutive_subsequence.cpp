#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        int lcs = 0;
        unordered_map<int, int> um1, um2;
        for (int i = 0; i < N; i++)
            um1[arr[i]] = i + 1;
        for (int i = 0; i < N; i++)
        {
            int j = arr[i];
            if (!um2[j])
            {
                int count = 0;
                while (um1[j])
                {
                    if (um2[j])
                    {
                        count += um2[j];
                        break;
                    }
                    um2[j]++;
                    count++;
                    j++;
                }
                um2[arr[i]] = count;
                if (count > lcs)
                    lcs = count;
            }
        }
        return lcs;
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