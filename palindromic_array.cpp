#include <iostream>
#include <string.h>
using namespace std;

// } Driver Code Ends
/*Complete the function below*/

class Solution
{
    bool palindrome(string n)
    {
        for (int i = 0; i < n.size() / 2; i++)
            if (n[i] != n[n.size() - i - 1])
                return false;
        return true;
    }

public:
    int PalinArray(int a[], int n)
    {
        // code here
        for (int i = 0; i < n; i++)
            if (!palindrome(to_string(a[i])))
                return 0;
        return 1;
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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.PalinArray(a, n) << endl;
    }
} // } Driver Code Ends