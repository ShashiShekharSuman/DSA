#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        // code here
        vector<int> spiralTraversal;
        int rstart = 0, rend = r - 1,
            cstart = 0, cend = c - 1;

        while (rstart <= rend && cstart <= cend)
        {
            for (int i = cstart; i <= cend; i++)
                spiralTraversal.push_back(matrix[rstart][i]);
            if (rstart++ == rend)
                continue;
            for (int i = rstart; i <= rend; i++)
                spiralTraversal.push_back(matrix[i][cend]);
            if (cend-- == cstart)
                continue;
            for (int i = cend; i >= cstart; i--)
                spiralTraversal.push_back(matrix[rend][i]);
            rend--;
            for (int i = rend; i >= rstart; i--)
                spiralTraversal.push_back(matrix[i][cstart]);
            cstart++;
        }

        return spiralTraversal;
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
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends