#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    bool kPartition(int a[], int n, int k, int i, int sum, int partition_sum, unordered_set<int> &s)
    {
        if (k == 0)
            return s.size() == n;
        if (sum == 0)
            return kPartition(a, n, k - 1, 0, partition_sum, partition_sum, s);

        for (int j = i; j < n; j++)
        {
            if (s.find(j) != s.end() || sum - a[j] < 0)
                continue;
            s.insert(j);
            if (kPartition(a, n, k, j + 1, sum - a[j], partition_sum, s))
                return true;
            s.erase(j);
            while (j > i && a[j] == a[j - 1])
                j++;
        }
        return false;
    }

public:
    /*
    Given an integer array a[ ] of N elements and an integer K, the task is to check if the array a[ ] could be divided into K non-empty subsets with equal sum of elements.
    Note: All elements of this array should be part of exactly one partition.
    */
    bool isKPartitionPossible(int a[], int n, int k)
    {
        // Your code here
        unordered_set<int> s;
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += a[i];
        if (sum % k != 0)
            return false;
        sum /= k;
        return kPartition(a, n, k, 0, sum, sum, s);
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.isKPartitionPossible(a, n, k) << endl;
    }
} // } Driver Code Ends