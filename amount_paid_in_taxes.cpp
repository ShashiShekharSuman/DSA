#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double tax = 0, dollor = 0, total = 0, i;
        for (i = 0; i < brackets.size(); i++)
        {
            dollor = brackets[i][0] - (i > 0 ? brackets[i - 1][0] : 0);
            if (total + dollor > income)
                break;
            total += dollor;
            tax += dollor * brackets[i][1] / 100;
        }
        if (i < brackets.size())
            tax += (income - total) * brackets[i][1] / 100;
        return tax;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, income;
        cin >> n;
        vector<vector<int>> brackets(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            cin >> brackets[i][0] >> brackets[i][1];
        }
        cin >> income;
        Solution obj;
        cout << obj.calculateTax(brackets, income) << endl;
    }
    return 0;
}