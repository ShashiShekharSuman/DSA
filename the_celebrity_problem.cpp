// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // code here
        bool isZeroCelebrity = true;
        for (int i = 0; i < n; i++)
        {
            if (M[0][i] == 1 && M[i][0] == 0)
            {
                isZeroCelebrity = false;
                bool isCelebrity = true;
                for (int j = 0; j < n; j++)
                {
                    if (M[i][j] == 1)
                    {
                        isCelebrity = false;
                        break;
                    }
                }
                if (isCelebrity)
                    return i;
            }
            if (i != 0 && M[i][0] == 0)
                isZeroCelebrity = false;
        }

        if (isZeroCelebrity)
            return 0;
        return -1;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends