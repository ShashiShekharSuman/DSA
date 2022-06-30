#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &v1, const vector<int> &v2)
             { return v1[1] < v2[1]; });
        vector<vector<int>> queue;
        for (int i = 0; i < people.size(); i++)
        {
            int count = 0, limit = people[i][1];
            for (int j = 0; j < queue.size(); j++)
            {
                if (queue[j][0] >= people[i][0] && count <= limit)
                    count++;
                if (count > limit)
                    swap(people[i], queue[j]);
            }
            queue.push_back(people[i]);
        }
        return queue;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> people(n);

        for (int i = 0; i < n; i++)
            cin >> people[i][0] >> people[i][1];

        Solution obj;
        vector<vector<int>> result = obj.reconstructQueue(people);
        for (auto i : result)
            cout << i[0] << " " << i[1] << endl;
        cout << endl;
    }
    return 0;
}