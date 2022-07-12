// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void topologicalSort(int node, vector<vector<int>> &order, vector<bool> &visited, string &s)
    {
        visited[node] = true;
        for (auto i : order[node])
            if (!visited[i])
                topologicalSort(i, order, visited, s);
        s += (char)(node + 'a');
    }

public:
    /*
    Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
    Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
    */
    string findOrder(string dict[], int N, int K)
    {
        // code here
        vector<bool> visited(K, false);
        vector<vector<int>> order(K);
        string s = "";
        for (int i = 1; i < N; i++)
        {
            int j = 0;
            while (dict[i][j] == dict[i - 1][j])
                j++;
            if (j < min(dict[i].size(), dict[i - 1].size()))
                order[dict[i][j] - 'a'].push_back(dict[i - 1][j] - 'a');
        }
        for (int i = 0; i < K; i++)
            if (!visited[i])
                topologicalSort(i, order, visited, s);
        return s;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b)
{
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++)
    {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends