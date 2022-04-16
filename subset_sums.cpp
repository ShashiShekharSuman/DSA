#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void subsetSum(const vector<int> &arr, const int &n, int i, int sum, vector<int> &subsetSums)
    {
        if (i == n)
        {
            subsetSums.push_back(sum);
            return;
        }
        subsetSum(arr, n, i + 1, sum + arr[i], subsetSums);
        subsetSum(arr, n, i + 1, sum, subsetSums);
    }

public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        sort(arr.begin(), arr.end());
        vector<int> subsetSums;
        subsetSum(arr, N, 0, 0, subsetSums);
        return subsetSums;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends