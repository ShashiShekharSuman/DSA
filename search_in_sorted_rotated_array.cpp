#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int transition_index(int A[], int l, int h)
    {
        int i = l, j = h, n = h - l + 1;
        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (A[mid] < A[(mid + n - 1) % n] &&
                A[mid] < A[(mid + 1) % n])
                return mid;
            if (A[h] < A[mid])
                i = mid + 1;
            else
                j = mid - 1;
        }
        return l;
    }

    int binary_search(int A[], int l, int h, int key)
    {
        while (l <= h)
        {
            int mid = l + (h - l) / 2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] < key)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }

public:
    int search(int A[], int l, int h, int key)
    {
        // complete the function here
        int index = transition_index(A, l, h),
            left_search = binary_search(A, l, index - 1, key),
            right_search = binary_search(A, index, h, key);

        return left_search == -1 ? right_search == -1 ? -1 : right_search : left_search;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
    return 0;
} // } Driver Code Ends