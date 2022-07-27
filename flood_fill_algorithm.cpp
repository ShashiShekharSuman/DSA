#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dx[4] = {1, 0, -1, 0},
        dy[4] = {0, 1, 0, -1};

    bool isValid(int i, int j, const vector<vector<int>> &image, int prevColor)
    {
        return i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && image[i][j] == prevColor;
    }

    void fill(vector<vector<int>> &image, int i, int j, int newColor, int prevColor)
    {
        if (image[i][j] == newColor)
            return;
        image[i][j] = newColor;
        for (int k = 0; k < 4; k++)
            if (isValid(i + dx[k], j + dy[k], image, prevColor))
                fill(image, i + dx[k], j + dy[k], newColor, prevColor);
    }

public:
    /*
    An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

    Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

    To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.
    */
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends