// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // define min heap
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;
    // To avoid repetition
    // Initialise min heap with first row
    for (int i = 0; i < n; i++)
        pq.push({mat[0][i], {0, i}});
    // pop min elements from heap k-1 times and while doing so
    // insert the element below the min element to the heap
    for (int i = 0; i < k - 1; i++)
    {
        int p = pq.top().second.first,  // row
            q = pq.top().second.second; // column

        pq.pop();
        if (p + 1 < n)
            pq.push({mat[p + 1][q], {p + 1, q}});
    }
    return pq.top().first; // return kth element
}
