#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    There is an n x n 0-indexed grid with some artifacts buried in it. You are given the integer n and a 0-indexed 2D integer array artifacts describing the positions of the rectangular artifacts where artifacts[i] = [r1i, c1i, r2i, c2i] denotes that the ith artifact is buried in the subgrid where:
        > (r1i, c1i) is the coordinate of the top-left cell of the ith artifact and
        > (r2i, c2i) is the coordinate of the bottom-right cell of the ith artifact.
    You will excavate some cells of the grid and remove all the mud from them. If the cell has a part of an artifact buried underneath, it will be uncovered. If all the parts of an artifact are uncovered, you can extract it.

    Given a 0-indexed 2D integer array dig where dig[i] = [ri, ci] indicates that you will excavate the cell (ri, ci), return the number of artifacts that you can extract.

    The test cases are generated such that:
        > No two artifacts overlap.
        > Each artifact only covers at most 4 cells.
        > The entries of dig are unique.
    */
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig)
    {
        int found = 0;
        vector<vector<bool>> grid(n, vector<bool>(n, false));
        for (auto i : dig)
            grid[i[0]][i[1]] = true;
        for (auto k : artifacts)
        {
            for (int i = k[0]; i <= k[2]; i++)
                for (int j = k[1]; j <= k[3]; j++)
                {
                    if (!grid[i][j])
                    {
                        found--;
                        i = n;
                        j = n;
                    }
                }
            found++;
        }
        return found;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> artifacts(n, vector<int>(4)), dig(m, vector<int>(2));

        for (int i = 0; i < n; i++)
            cin >> artifacts[i][0] >> artifacts[i][1] >> artifacts[i][2] >> artifacts[i][3];

        for (int i = 0; i < m; i++)
            cin >> dig[i][0] >> dig[i][0];

        Solution obj;
        cout << obj.digArtifacts(n, artifacts, dig) << endl;
    }

    return 0;
}