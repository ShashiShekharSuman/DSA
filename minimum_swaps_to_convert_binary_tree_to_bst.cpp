/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{

    void postOrderToInOrder(vector<int> &A, int i, vector<vector<int>> &inorder)
    {
        if (i >= A.size())
            return;
        postOrderToInOrder(A, 2 * i + 1, inorder);
        inorder.push_back({A[i], (int)inorder.size()});
        postOrderToInOrder(A, 2 * i + 2, inorder);
    }

public:
    /*
    Given an array A[] which represents a Complete Binary Tree i.e, if index i is the parent, index 2*i + 1 is the left child and index 2*i + 2 is the right child.
    The task is to find the minimum number of swaps required to convert it into a Binary Search Tree.
    */
    int minSwaps(vector<int> &A, int n)
    {
        // Write your code here
        int swaps = 0;
        vector<vector<int>> inorder;
        postOrderToInOrder(A, 0, inorder);
        sort(inorder.begin(), inorder.end());
        for (int i = 0; i < n; i++)
        {
            while (inorder[i][1] != i)
            {
                swap(inorder[i], inorder[inorder[i][1]]);
                swaps++;
            }
        }
        return swaps;
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
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        Solution ob;
        int ans = ob.minSwaps(A, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends