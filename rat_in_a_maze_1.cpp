// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isValid(int i, int j, int n, vector<vector<int>> &m)
    {
        return i >= 0 &&
               i < n &&
               j >= 0 &&
               j < n &&
               m[i][j];
    }

    void traversePath(int i, int j, int n, vector<vector<int>> &m, string str, vector<string> &paths)
    {
        if (i == n - 1 && j == n - 1)
        {
            paths.push_back(str);
            return;
        }

        m[i][j] = 0;

        if (isValid(i + 1, j, n, m))
        {
            str += "D";
            traversePath(i + 1, j, n, m, str, paths);
            str.pop_back();
        }

        if (isValid(i, j - 1, n, m))
        {
            str += "L";
            traversePath(i, j - 1, n, m, str, paths);
            str.pop_back();
        }

        if (isValid(i, j + 1, n, m))
        {
            str += "R";
            traversePath(i, j + 1, n, m, str, paths);
            str.pop_back();
        }

        if (isValid(i - 1, j, n, m))
        {
            str += "U";
            traversePath(i - 1, j, n, m, str, paths);
            str.pop_back();
        }

        m[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        if (!isValid(0, 0, n, m))
            return {"-1"};
        vector<string> paths;
        string str = "";
        traversePath(0, 0, n, m, "", paths);
        if (paths.size())
            return paths;
        return {"-1"};
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
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends