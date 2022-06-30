// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
    {
        // Code Here
        int n = a.size(), m = a[0].size(), sum,
            rstart, cstart, rend, cend, size = 0;

        vector<vector<int>> b = a;
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
            for (int j = 1; j < m; j++)
                a[i][j] += a[i][j - 1];

        for (int i = 0; i < m; i++)
        {
            for (int j = i; j < m; j++)
            {
                sum = 0;
                map.clear();
                for (int k = 0; k < n; k++)
                {
                    sum += a[k][j] - (i > 0 ? a[k][i - 1] : 0);
                    if (map.find(sum) != map.end() || sum == 0)
                    {
                        if ((j - i + 1) * (k - (sum == 0 ? -1 : map[sum])) > size)
                        {
                            size = (j - i + 1) * (k - (sum == 0 ? -1 : map[sum]));
                            rstart = (sum == 0 ? 0 : map[sum] + 1);
                            rend = k;
                            cstart = i;
                            cend = j;
                        }
                    }
                    else
                        map[sum] = k;
                }
            }
        }

        vector<vector<int>> zero;
        if (size == 0)
            return zero;

        for (int i = rstart; i <= rend; i++)
        {
            zero.push_back(vector<int>());
            for (int j = cstart; j <= cend; j++)
                zero[i - rstart].push_back(b[i][j]);
        }

        return zero;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if (ans.size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                for (int j = 0; j < ans[0].size(); j++)
                {
                    cout << ans[i][j] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
} // } Driver Code Ends