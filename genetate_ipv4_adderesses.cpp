#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    vector<string> genIp(string &s)
    {
        // Your code here
        int size = s.size();
        vector<string> ip_addrs;
        string n1 = "", n2 = "", n3 = "", n4 = "";
        for (int i = 0; i < min(3, size - 3); i++)
        {
            n1 += s[i];
            for (int j = i + 1; j < min(i + 4, size - 2); j++)
            {
                n2 += s[j];
                for (int k = j + 1; k < min(j + 4, size - 1); k++)
                {
                    n3 += s[k];
                    for (int l = k + 1; l < min(k + 4, size); l++)
                        n4 += s[l];
                    if (stoi(n1) < 256 && (n1.size() == 1 || (n1.size() > 1 && n1[0] != '0')) &&
                        stoi(n2) < 256 && (n2.size() == 1 || (n2.size() > 1 && n2[0] != '0')) &&
                        stoi(n3) < 256 && (n3.size() == 1 || (n3.size() > 1 && n3[0] != '0')) &&
                        stoi(n4) < 256 && (n4.size() == 1 || (n4.size() > 1 && n4[0] != '0')) &&
                        n1.size() + n2.size() + n3.size() + n4.size() == size)
                        ip_addrs.push_back(n1 + "." + n2 + "." + n3 + "." + n4);
                    for (int l = k + 1; l < min(k + 4, size); l++)
                        n4.pop_back();
                }
                for (int k = j + 1; k < min(j + 4, size - 1); k++)
                    n3.pop_back();
            }
            for (int j = i + 1; j < min(i + 4, size - 2); j++)
                n2.pop_back();
        }
        if (ip_addrs.size())
            return ip_addrs;
        return {"-1"};
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if (str.size() == 0)
            cout << -1 << "\n";
        else
        {
            for (auto &u : str)
            {
                cout << u << "\n";
            }
        }
    }
} // } Driver Code Ends