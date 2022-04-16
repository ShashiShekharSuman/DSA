// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        // Your code here
        int number = 0;
        bool isNegative = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (i == 0 && str[i] == '-')
            {
                isNegative = true;
                continue;
            }
            if (str[i] < '0' || str[i] > '9')
                return -1;
            number = number * 10 + str[i] - '0';
        }
        if (isNegative)
            return -number;
        return number;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends