#include <bits/stdc++.h>
using namespace std;

class TreeAncestor
{
    vector<vector<int>> expAncestor;

public:
    /*
    You are given a tree with n nodes numbered from 0 to n - 1 in the form of a parent array parent where parent[i] is the parent of ith node. The root of the tree is node 0. Find the kth ancestor of a given node.
    The kth ancestor of a tree node is the kth node in the path from that node to the root node.
    Implement the TreeAncestor class:
        > TreeAncestor(int n, int[] parent) Initializes the object with the number of nodes in the tree and the parent array.
        > int getKthAncestor(int node, int k) return the kth ancestor of the given node node. If there is no such ancestor, return -1.
    */
    TreeAncestor(int n, vector<int> &parent)
    {
        expAncestor = vector<vector<int>>(parent.size(), vector<int>(log2(parent.size()) + 1, -1));
        for (int i = 0; i < expAncestor[0].size(); i++)
            for (int j = 0; j < parent.size(); j++)
                if (i == 0)
                    expAncestor[j][i] = parent[j];
                else if (expAncestor[j][i - 1] != -1)
                    expAncestor[j][i] = expAncestor[expAncestor[j][i - 1]][i - 1];
    }

    int getKthAncestor(int node, int k)
    {
        int i = 0;
        while (k && node != -1)
        {
            if (k & 1)
                node = expAncestor[node][i];
            k >>= 1;
            i++;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q, node, k;
        cin >> n;
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            cin >> parent[i];
        TreeAncestor *obj = new TreeAncestor(n, parent);
        cin >> q;
        while (q--)
        {
            cin >> node >> k;
            cout << obj->getKthAncestor(node, k) << "\n";
        }
    }
    return 0;
}