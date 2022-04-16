#include <bits/stdc++.h>
using namespace std;

int strstr(string, string);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;

        cin >> a;
        cin >> b;

        cout << strstr(a, b) << endl;
    }
}
// } Driver Code Ends

// Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    // Your code here
    int i = 0, j = 0, index = 0;
    while (i < s.size() && j < x.size())
    {
        if (s[i] == x[j])
        {
            i++;
            j++;
        }
        else
        {
            i = ++index;
            j = 0;
        }
    }
    if (j == x.size())
        return index;
    return -1;
}