#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution
{
public:
    int isValid(string s)
    {
        // code here
        int start = 0, dotCount = 0, i = 0;
        while (dotCount < 4)
        {
            start = i;
            while (i < s.size() && s[i] != '.')
            {
                if (s[i] > '9' || s[i] < '0')
                    return 0;
                i++;
            }
            string number = s.substr(start, i - start);
            if (number.size() == 0 ||
                number.size() > 3 ||
                (number.size() > 1 && number[0] == '0') ||
                stoi(number) > 255)
                return 0;
            if (dotCount < 3 && i >= s.size())
                return 0;
            if (dotCount == 3 && i < s.size())
                return 0;
            i++;
            dotCount++;
        }
        return 1;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
} // } Driver Code Ends