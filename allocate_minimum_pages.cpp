// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
public:
    bool allocate(int A[], int N, int M, int maxPages)
    {
        int count = 1, pages = 0;
        for (int i = 0; i < N; i++)
        {
            if (pages + A[i] > maxPages)
            {
                count++;
                pages = A[i];
            }
            else
                pages += A[i];
        }
        return !(count > M);
    }

    int searchSpace(int A[], int N, int M, int start, int end)
    {
        int maxPages = (start + end) / 2;
        if (start == end)
            return maxPages;
        if (allocate(A, N, M, maxPages))
        {
            searchSpace(A, N, M, start, maxPages);
        }
        else
            searchSpace(A, N, M, maxPages + 1, end);
    }
    /*
    You are given N number of books. Every ith book has Ai number of pages. The books are arranged in ascending order.

    You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.

    Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

    Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
    */
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;
        int lowerLimit = -1, upperLimit = 0;
        for (int i = 0; i < N; i++)
        {
            lowerLimit = max(A[i], lowerLimit);
            upperLimit += A[i];
        }
        return searchSpace(A, N, M, lowerLimit, upperLimit);
    }

    // DP Solution O(N*M)

    // int partition(const int A[], int N, int M, int i, vector<vector<int>> &dp) {
    //     if (dp[i][M] != -1) return dp[i][M];
    //     if (M <= 1) return dp[i][M] = i == 0 ? A[N-1] : A[N-1] - A[i-1];
    //     int maxPages, minPages = INT_MAX;
    //     for (int j = i; j <= N-M; j++) {
    //         maxPages = max(i == 0 ? A[j] : A[j] - A[i-1], partition(A, N, M-1, j+1, dp));
    //         minPages = min(maxPages, minPages);
    //     }
    //     return dp[i][M] = minPages;
    // }

    // //Function to find minimum number of pages.
    // int findPages(int A[], int N, int M) {
    //     //code here
    //     if (M > N) return -1;
    //     vector<vector<int>> dp(N, vector<int>(M+1, -1));
    //     for (int i = 1; i < N; i++) A[i] += A[i-1];
    //     return partition(A, N, M, 0, dp);
    // }
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
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends