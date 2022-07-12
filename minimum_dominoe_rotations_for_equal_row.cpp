#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

    We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

    Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

    If it cannot be done, return -1.
    */
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int no_of_dominoes = tops.size();
        vector<vector<int>> frequency(6, vector<int>(3, 0));
        for (int i = 0; i < no_of_dominoes; i++)
        {
            frequency[tops[i] - 1][1]++;
            frequency[bottoms[i] - 1][2]++;
            if (++frequency[tops[i] - 1][0] == no_of_dominoes)
            {
                return min(no_of_dominoes - frequency[tops[i] - 1][1], no_of_dominoes - frequency[tops[i] - 1][2]);
            }
            if (tops[i] != bottoms[i])
            {
                if (++frequency[bottoms[i] - 1][0] == no_of_dominoes)
                {
                    return min(no_of_dominoes - frequency[bottoms[i] - 1][1], no_of_dominoes - frequency[bottoms[i] - 1][2]);
                }
            }
        }
        return -1;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> tops(n), bottoms(n);
        for (int i = 0; i < n; i++)
        {
            cin >> tops[i] >> bottoms[i];
        }
        Solution obj;
        cout << obj.minDominoRotations(tops, bottoms) << endl;
    }
}