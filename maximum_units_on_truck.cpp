#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

        > numberOfBoxesi is the number of boxes of type i.
        > numberOfUnitsPerBoxi is the number of units in each box of the type i.

    You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

    Return the maximum total number of units that can be put on the truck.
    */
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &box1, const vector<int> &box2)
             { return box1[1] > box2[1]; });
        int i = 0, units = 0;
        while (truckSize && i < boxTypes.size())
        {
            units += min(truckSize, boxTypes[i][0]) * boxTypes[i][1];
            truckSize -= min(truckSize, boxTypes[i++][0]);
        }
        return units;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, truckSize;
        cin >> n >> truckSize;
        vector<vector<int>> boxTypes(n, vector<int>(2));

        for (int i = 0; i < n; i++)
            cin >> boxTypes[i][0] >> boxTypes[i][0];

        Solution obj;
        cout << obj.maximumUnits(boxTypes, truckSize) << "\n";
    }
    return 0;
}