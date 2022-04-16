#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
    int first;
    int second;
};*/

/*You are required to complete this method*/
bool comparator(val p1, val p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return (p1.second < p2.second);
}

int maxChainLen(struct val p[], int n)
{
    // Your code here
    sort(p, p + n, comparator);
    int count = 1, i = 0, j = 1;
    while (j < n)
    {
        if (p[i].second < p[j].first)
        {
            count++;
            i = j;
            j++;
        }
        else
            j++;
    }
    return count++;
}