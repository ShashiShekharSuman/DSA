#include <bits/stdc++.h>
using namespace std;

string firstRepChar(string s);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << firstRepChar(s) << endl;
    }
    return 0;
} // } Driver Code Ends

string firstRepChar(string s)
{
    // code here.
    string result;
    vector<int> frequency(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        frequency[s[i] - 'a']++;
        if (frequency[s[i] - 'a'] > 1)
            return result = s[i];
    }
    return "-1";
}