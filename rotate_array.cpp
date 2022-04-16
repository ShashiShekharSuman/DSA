#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    //  void rotateArr(int arr[], int d, int n){
    //      // code here
    //      for (int i = 0; i < n; i++) arr[i] += (arr[(i+d)%n]%(int)(1e5+1)) * (1e5+1);
    //      for (int i = 0; i < n; i++) arr[i] /= (1e5+1);
    //  }

    void rotateArr(int arr[], int d, int n)
    {
        // code here
        long long temp;
        for (int i = 0; i < n; i++)
        {
            temp = arr[(i + d) % n];
            if (temp < 0)
                temp = INT_MAX - temp;
            temp = arr[i] + (temp % (int)(1e5 + 1)) * (1e5 + 1);
            if (temp > INT_MAX)
                temp = INT_MAX - temp;
            arr[i] = temp;
        }
        for (int i = 0; i < n; i++)
        {
            temp = arr[i];
            if (temp < 0)
                temp = INT_MAX - temp;
            temp = temp / (1e5 + 1);
            arr[i] = temp;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    // taking testcases
    cin >> t;

    while (t--)
    {
        int n, d;

        // input n and d
        cin >> n >> d;

        int arr[n];

        // inserting elements in the array
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        // calling rotateArr() function
        ob.rotateArr(arr, d, n);

        // printing the elements of the array
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends