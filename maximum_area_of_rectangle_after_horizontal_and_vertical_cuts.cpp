#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

        > horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
        > verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.

    Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
    */
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int length = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]),
            breadth = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]),
            mod = 1e9 + 7;

        for (int i = 1; i < horizontalCuts.size(); i++)
            length = max(length, horizontalCuts[i] - horizontalCuts[i - 1]);

        for (int i = 1; i < verticalCuts.size(); i++)
            breadth = max(breadth, verticalCuts[i] - verticalCuts[i - 1]);

        return ((long long)length * (long long)breadth) % mod;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int h, w, h_cuts, v_cuts;
        cin >> h >> w >> h_cuts >> v_cuts;
        vector<int> horizontalCuts(h_cuts),
            verticalCuts(v_cuts);

        for (int i = 0; i < h_cuts; i++)
            cin >> horizontalCuts[i];
        for (int i = 0; i < v_cuts; i++)
            cin >> verticalCuts[i];

        Solution obj;
        cout << obj.maxArea(h, w, horizontalCuts, verticalCuts) << "\n";
    }
    return 0;
}