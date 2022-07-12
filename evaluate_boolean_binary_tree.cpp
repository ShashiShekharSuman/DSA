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

/* utility that allocates a new TreeNode
   with the given val */

TreeNode *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    TreeNode *root = new TreeNode(stoi(ip[0]));

    // Push the root to the queue
    queue<TreeNode *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        TreeNode *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new TreeNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new TreeNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
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
public:
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val;
        bool left = evaluateTree(root->left),
             right = evaluateTree(root->right);
        if (root->val == 2)
            return left || right;
        else
            return left && right;
    }
};

int main()
{

    int t;
    cin >> t;
    getchar();

    while (t--)
    {

        string str;
        getline(cin, str);

        TreeNode *root = buildTree(str);
        Solution obj;
        cout << obj.evaluateTree(root) << "\n";
    }

    return 0;
}