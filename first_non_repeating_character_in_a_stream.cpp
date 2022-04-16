#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        // Code here
        string result = "";
        int index = 0;
        vector<int> count(26, 0);
        for (int i = 0; i < A.size(); i++)
        {
            count[A[i] - 'a']++;
            while (index <= i)
            {
                if (count[A[index] - 'a'] == 1)
                    break;
                index++;
            }
            if (index > i)
                result += '#';
            else
                result += A[index];
        }
        return result;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends