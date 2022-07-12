/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    double get_distance(double x, double y, vector<pair<int, int>> &p)
    {
        double distance = 0;
        for (auto i : p)
            distance += sqrt(pow(x - i.first, 2) + pow(y - i.second, 2));
        return distance;
    }

public:
    /*
    Given a set of coordinates points of the form [p, q] and a line L of the form ax + by + c = 0. The task is to find a point on a given line for which the sum of distances from a given set of coordinates is minimum.
    */
    double findOptimumCost(tuple<int, int, int> l, vector<pair<int, int>> &p, int n)
    {
        // Write your code here
        double low = -1e3, high = 1e3, x1, y1, s1, x2, y2, s2;

        while (low < high)
        {
            x1 = low + (high - low) / 2;
            y1 = -(get<2>(l) + get<0>(l) * x1) / get<1>(l);
            s1 = get_distance(x1, y1, p);

            x2 = x1 + 1e-3;
            y2 = -(get<2>(l) + get<0>(l) * x2) / get<1>(l);
            s2 = get_distance(x2, y2, p);

            if (abs(s2 - s1) < 1e-9)
                break;
            else if (s1 > s2)
                low = x1;
            else
                high = x1;
        }
        return s1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        tuple<int, int, int> line;
        int a, b, c;
        cin >> a >> b >> c;
        line = make_tuple(a, b, c);
        int n;
        cin >> n;
        vector<pair<int, int>> points;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        Solution ob;
        double ans = ob.findOptimumCost(line, points, n);

        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
// } Driver Code Ends