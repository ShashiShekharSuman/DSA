// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*
    You live in Geek land. Geek land can be seen as a grid of shape nXm.Their are k enemy at k positions. Each enemy blocks the row and column to which it belongs. You have to find the largest continuous area that is not blocked.No two enemies share the same row or the same column.
    */
    int largestArea(int n, int m, int k, vector<vector<int>> &e)
    {
        //  code here
        if (k == 0)
            return n * m;
        vector<int> r, c;
        for (auto enemy : e)
        {
            r.push_back(enemy[0]);
            c.push_back(enemy[1]);
        }
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        int l = r[0] - 1, b = c[0] - 1;
        for (int i = 1; i < k; i++)
        {
            l = max(l, r[i] - r[i - 1] - 1);
            b = max(b, c[i] - c[i - 1] - 1);
        }
        l = max(l, n - r[k - 1]);
        b = max(b, m - c[k - 1]);
        return l * b;
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
        int k;
        cin >> k;
        vector<vector<int>> e(k, vector<int>(2));
        for (int i = 0; i < k; i++)
            cin >> e[i][0] >> e[i][1];
        Solution a;
        cout << a.largestArea(n, m, k, e) << endl;
    }
    return 0;
} // } Driver Code Ends