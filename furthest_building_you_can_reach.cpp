#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int index = 0;
        priority_queue<int> pq;
        while (index < heights.size() - 1)
        {
            if (heights[index] >= heights[index + 1])
            {
                index++;
                continue;
            }
            if (bricks - (heights[index + 1] - heights[index]) >= 0)
            {
                bricks -= heights[index + 1] - heights[index];
                pq.push(heights[index + 1] - heights[index]);
                index++;
            }
            else if (ladders)
            {
                if (pq.empty() || heights[index + 1] - heights[index] >= pq.top())
                {
                    ladders--;
                    index++;
                }
                else
                {
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
            }
            else
                break;
        }
        return index;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, bricks, ladders;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++)
            cin >> heights[i];
        cin >> bricks >> ladders;
        Solution obj;
        cout << obj.furthestBuilding(heights, bricks, ladders) << "\n";
    }
    return 0;
}