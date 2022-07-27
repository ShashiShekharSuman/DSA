#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;

    TreeNode()
    {
        this->val = 0;
        this->left = this->right = NULL;
    }

    TreeNode(int val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }

    TreeNode(int val, TreeNode *left, TreeNode *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

void printTree(TreeNode *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        cout << root->val;
        printTree(root->right);
    }
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder, int &index, int i, int j)
    {
        if (index >= preorder.size() || i == j)
            return NULL;
        int found = 0;
        while (preorder[index] != inorder[found])
            found++;
        TreeNode *root = new TreeNode(preorder[index++]);
        root->left = buildTree(preorder, inorder, index, i, found);
        root->right = buildTree(preorder, inorder, index, found + 1, j);
        return root;
    }

public:
    /*
    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
    */
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int index = 0;
        return buildTree(preorder, inorder, index, 0, preorder.size());
    }
};

int main()
{

    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> preorder(n), inorder(n);
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];

        Solution obj;
        printTree(obj.buildTree(preorder, inorder));
        cout << endl;
    }

    return 0;
}