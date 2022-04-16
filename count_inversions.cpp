#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

    long long inversion_Count = 0;
    void merge(long long arr[], int s, int m, int e)
    {
        long long result[e - s];
        int i = s, k = m, j = 0;
        while (i < m && k < e)
        {
            if (arr[i] <= arr[k])
                result[j++] = arr[i++];
            else
            {
                inversion_Count += m - i;
                result[j++] = arr[k++];
            }
        }
        while (i < m)
            result[j++] = arr[i++];
        while (k < e)
            result[j++] = arr[k++];
        for (int p = 0; p < e - s; p++)
            arr[s + p] = result[p];
    }

    void mergeSort(long long arr[], int start, int end)
    {
        int n = end - start, mid = n - n / 2;
        if (n == 1)
            return;
        mergeSort(arr, start, start + mid);
        mergeSort(arr, start + mid, end);
        merge(arr, start, start + mid, end);
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr, 0, N);
        return inversion_Count;
    }
};

// { Driver Code Starts.

int main()
{

    long long T;
    cin >> T;

    while (T--)
    {
        long long N;
        cin >> N;

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }

    return 0;
}
// } Driver Code Ends