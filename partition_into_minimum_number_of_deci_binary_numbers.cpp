#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPartitions(string n)
    {
        return *max_element(n.begin(), n.end()) - '0';
    }
};

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string n;
        getline(cin, n);
        Solution obj;
        cout << obj.minPartitions(n) << endl;
    }
}