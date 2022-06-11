#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solve(vector<int> &A)
    {
        if (A.size() < 3)
            return 0;
        int max_3sum = 0, next_max = 0;
        set<int> prev;
        prev.insert(A[0]);
        vector<int> right(A.size(), 0);
        for (int i = A.size() - 1; i > -1; i--)
        {
            if (A[i] > next_max)
            {
                right[i] = 0;
                next_max = A[i];
            }
            else
                right[i] = next_max;
        }
        for (int i = 1; i < A.size() - 1; i++)
        {
            auto left = prev.lower_bound(A[i]);
            left--;
            if (left != prev.end() && A[i] < right[i] && *left < A[i])
                max_3sum = max(max_3sum, *left + A[i] + right[i]);
            prev.insert(A[i]);
        }
        return max_3sum;
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
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.solve(A) << "\n";
    }
    return 0;
}
