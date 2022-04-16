#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*The function takes an array of heights, width and
    length as its 3 arguments where each index i value
    determines the height, width, length of the ith box.
    Here n is the total no of boxes.*/
    int maxHeight(int height[], int width[], int length[], int n)
    {
        // Your code here
        vector<vector<int>> box;
        vector<int> dp(3 * n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            box.push_back({height[i], width[i], length[i]});
            box.push_back({width[i], length[i], height[i]});
            box.push_back({length[i], height[i], width[i]});
        }

        sort(box.begin(), box.end(), [](const vector<int> &box1, const vector<int> &box2)
             { return box1[0] * box1[1] < box2[0] * box2[1]; });

        int maxHeight = 0;
        for (int i = 0; i < 3 * n; i++)
        {
            dp[i] = box[i][2];
            for (int j = 0; j < i; j++)
            {
                if (max(box[i][0], box[i][1]) > max(box[j][0], box[j][1]) &&
                    min(box[i][0], box[i][1]) > min(box[j][0], box[j][1]))
                    dp[i] = max(dp[i], dp[j] + box[i][2]);
            }
            maxHeight = max(maxHeight, dp[i]);
        }

        return maxHeight;
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

        int A[105], B[105], C[105];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int j = 0; j < n; j++)
            cin >> B[j];
        for (int k = 0; k < n; k++)
            cin >> C[k];
        Solution ob;
        cout << ob.maxHeight(A, B, C, n) << endl;
    }

    return 0;
}
// } Driver Code Ends