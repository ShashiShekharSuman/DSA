#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int>> fourSum(vector<int> &arr, int k)
    {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> quadruples;
        // if (arr.size() < 4) return quadruple;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int left = j + 1, right = n - 1, pairSum = k - arr[i] - arr[j];
                while (left < right)
                {
                    if (arr[left] + arr[right] == pairSum)
                    {
                        quadruples.push_back({arr[i], arr[j], arr[left], arr[right]});
                        while (left < right && arr[left] == quadruples[quadruples.size() - 1][2])
                            left++;
                        while (left < right && arr[right] == quadruples[quadruples.size() - 1][3])
                            right--;
                    }
                    else if (arr[left] + arr[right] < pairSum)
                        left++;
                    else
                        right--;
                }
                while (j + 1 < n - 2 && arr[j] == arr[j + 1])
                    j++;
            }
            while (i + 1 < n - 3 && arr[i] == arr[i + 1])
                i++;
        }
        return quadruples;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int>> ans = ob.fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends