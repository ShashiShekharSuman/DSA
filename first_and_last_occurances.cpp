#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n, int x)
{
    // code here
    int first = -1, last = -1, i = 0, j = n - 1, mid;

    while (i + 1 < j)
    {
        mid = (i + j) / 2;
        if (arr[mid] < x)
            i = mid;
        else
            j = mid;
    }

    if (arr[i] == x)
        first = i;
    else if (arr[j] == x)
        first = j;
    else
        return {-1, -1};

    i = first, j = n - 1;
    while (i + 1 < j)
    {
        mid = (i + j) / 2;
        if (arr[mid] > x)
            j = mid;
        else
            i = mid;
    }
    if (arr[j] == x)
        last = j;
    else if (arr[i] == x)
        last = i;
    return {first, last};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        ans = find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends