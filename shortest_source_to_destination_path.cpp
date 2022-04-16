// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    bool isValid(int i, int j, int N, int M, vector<vector<int>> &A)
    {
        return i >= 0 && j >= 0 && i < N && j < M && A[i][j] == 1;
    }

public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        if (A[0][0] != 1)
            return -1;
        int shortestPath = 0,
            dx[4] = {-1, 1, 0, 0},
            dy[4] = {0, 0, -1, 1};
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({-1, -1});
        A[0][0] = 0;
        while (!q.empty())
        {
            if (q.front().first == -1)
            {
                q.pop();
                shortestPath++;
                if (!q.empty())
                    q.push({-1, -1});
                continue;
            }
            int i = q.front().first,
                j = q.front().second;
            q.pop();

            if (i == X && j == Y)
                return shortestPath;
            for (int k = 0; k < 4; k++)
            {
                if (isValid(i + dx[k], j + dy[k], N, M, A))
                {
                    A[i + dx[k]][j + dy[k]] = 0;
                    q.push({i + dx[k], j + dy[k]});
                }
            }
        }
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
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
} // } Driver Code Ends