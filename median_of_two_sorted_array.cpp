// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    double MedianOfArrays(vector<int> &array1, vector<int> &array2)
    {
        // Your code goes here
        int n = array1.size(), m = array2.size(), k = (n + m + 1) / 2;
        int low = max(0, k - m), high = min(k, n), mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mid - 1 >= 0 && mid - 1 < n &&
                k - mid >= 0 && k - mid < m &&
                array1[mid - 1] > array2[k - mid])
                high = mid - 1;
            else if (mid >= 0 && mid < n &&
                     k - mid - 1 >= 0 && k - mid - 1 < m &&
                     array2[k - mid - 1] > array1[mid])
                low = mid + 1;
            else
                break;
        }
        if ((n + m) & 1)
        {
            if (mid - 1 >= 0 && mid - 1 < n &&
                k - mid - 1 >= 0 && k - mid - 1 < m)
                return max(array1[mid - 1], array2[k - mid - 1]);
            else if (mid - 1 >= 0 && mid - 1 < n)
                return array1[mid - 1];
            else
                return array2[k - mid - 1];
        }

        else
        {
            double median = 0;
            if (mid - 1 >= 0 && mid - 1 < n &&
                k - mid - 1 >= 0 && k - mid - 1 < m)
                median += max(array1[mid - 1], array2[k - mid - 1]);
            else if (mid - 1 >= 0 && mid - 1 < n)
                median += array1[mid - 1];
            else
                median += array2[k - mid - 1];
            if (mid >= 0 && mid < n &&
                k - mid >= 0 && k - mid < m)
                median += min(array1[mid], array2[k - mid]);
            else if (mid >= 0 && mid < n)
                median += array1[mid];
            else
                median += array2[k - mid];
            return (double)(median / 2);
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> array1[i];
        }
        cin >> n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> array2[i];
        }
        Solution ob;
        cout << ob.MedianOfArrays(array1, array2) << endl;
    }
    return 0;
}

// } Driver Code Ends