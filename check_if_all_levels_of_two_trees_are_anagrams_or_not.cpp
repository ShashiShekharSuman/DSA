// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
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
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Given two binary trees, the task is to check if each of their levels are anagrams of each other or not.
    bool areAnagrams(Node *root1, Node *root2)
    {
        vector<vector<int>> level_order_traversal1, level_order_traversal2;
        vector<int> nodes1, nodes2;
        queue<Node *> q1, q2;
        q1.push(root1);
        q1.push(NULL);
        q2.push(root2);
        q2.push(NULL);
        while (!q1.empty() && !q2.empty())
        {
            if (!q1.front())
            {
                q1.pop();
                level_order_traversal1.push_back(nodes1);
                nodes1.resize(0);
                if (!q1.empty())
                    q1.push(NULL);
            }
            else
            {
                if (q1.front()->left)
                    q1.push(q1.front()->left);
                if (q1.front()->right)
                    q1.push(q1.front()->right);
                nodes1.push_back(q1.front()->data);
                q1.pop();
            }
            if (!q2.front())
            {
                q2.pop();
                level_order_traversal2.push_back(nodes2);
                nodes2.resize(0);
                if (!q2.empty())
                    q2.push(NULL);
            }
            else
            {
                if (q2.front()->left)
                    q2.push(q2.front()->left);
                if (q2.front()->right)
                    q2.push(q2.front()->right);
                nodes2.push_back(q2.front()->data);
                q2.pop();
            }
        }

        if (!q1.empty() || !q2.empty() || level_order_traversal1.size() != level_order_traversal2.size())
            return false;

        for (int i = 0; i < level_order_traversal1.size(); i++)
        {
            sort(level_order_traversal1[i].begin(), level_order_traversal1[i].end());
            sort(level_order_traversal2[i].begin(), level_order_traversal2[i].end());
            if (level_order_traversal1[i] != level_order_traversal2[i])
                return false;
        }

        return true;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}
// } Driver Code Ends