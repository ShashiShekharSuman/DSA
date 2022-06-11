// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here
        int median_index = (r * c) / 2 + 1;
        int start = matrix[0][0], end = matrix[0][c - 1], mid;

        // find start( = min) and end ( = max) from matrix
        for (int row = 1; row < r; row++)
        {
            start = min(start, matrix[row][0]);
            end = max(end, matrix[row][c - 1]);
        }

        while (start < end)
        {
            mid = start + (end - start) / 2;
            int index = 0;
            for (int row = 0; row < r; row++)
                index += (upper_bound(matrix[row].begin(), matrix[row].end(), mid) - matrix[row].begin());
            if (index < median_index)
                start = mid + 1;
            else
                end = mid;
        }

        return start;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
} // } Driver Code Ends