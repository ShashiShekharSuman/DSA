// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void select(int index, vector<vector<int>> &mat, vector<int> &atms, int k, int &result)
    {
        if (k == 0)
        {
            int max_distance = 0;
            for (int i = 0; i < mat.size(); i++)
            {
                int distance = INT_MAX;
                for (int j = 0; j < atms.size(); j++)
                    distance = min(distance, mat[i][atms[j]]);
                max_distance = max(max_distance, distance);
            }
            result = min(result, max_distance);
            return;
        }
        for (int i = index; i <= mat.size() - k; i++)
        {
            atms.push_back(i);
            select(index + 1, mat, atms, k - 1, result);
            atms.pop_back();
        }
    }

public:
    /*
    You have given N cities numbered from 0 to N-1. The distance b/w each pair of cities is given by N * N matrix MAT where MAT[i][j] denotes the distance b/w city i and j.
    The task is to select K (K<= N) ATM servers  in such a way that the maximum distance of a city from the ATM Server is minimized.
    */
    int selectKcities(int n, int k, vector<vector<int>> &mat)
    {
        // code here
        int result = INT_MAX;
        vector<int> atms;
        select(0, mat, atms, k, result);
        return result;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> mat(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution obj;
        int ans = obj.selectKcities(n, k, mat);

        cout << ans << endl;
    }
} // } Driver Code Ends