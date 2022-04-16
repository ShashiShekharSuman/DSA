#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to search a given number in row-column sorted matrix.

    bool search(vector<vector<int>> matrix, int n, int m, int x)
    {
        // code here
        int l, h;
        for (int i = 0; i < n; i++)
        {
            l = 0, h = m - 1;
            if (matrix[i][l] <= x && matrix[i][h] >= x)
            {
                while (l <= h)
                {
                    int mid = l + (h - l) / 2;
                    if (matrix[i][mid] == x)
                        return true;
                    else if (matrix[i][mid] > x)
                        h = mid - 1;
                    else
                        l = mid + 1;
                }
            }
        }
        return false;
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
        vector<vector<int>> matrix(n);

        for (int i = 0; i < n; i++)
        {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.search(matrix, n, m, x))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

// } Driver Code Ends