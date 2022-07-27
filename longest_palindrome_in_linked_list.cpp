// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node *new_node = new Node(new_data);

    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);

/* Driver program to test above function*/
int main()
{
    int T, n, l;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
        }

        cout << maxPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* The Node is defined
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int maxPalindrome(Node *head)
{
    // Your code here
    int maxLen = 0, n;
    vector<int> list;
    while (head)
    {
        list.push_back(head->data);
        head = head->next;
    }
    n = list.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = true;
            else if (j == i + 1)
                dp[i][j] = list[i] == list[j];
            else if (list[i] == list[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = false;
            if (dp[i][j])
                maxLen = max(j - i + 1, maxLen);
        }
    }
    return maxLen;
}