// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node *partition(struct Node *head, int x);

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

/* Function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct Node *head = NULL;
        struct Node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new Node(value);
                temp = head;
            }
            else
            {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends

// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node *partition(struct Node *head, int x)
{
    // code here
    Node *first = NULL, *second = NULL, *third = NULL,
         *fhead = NULL, *shead = NULL, *thead = NULL, *ptr = head;

    while (ptr)
    {
        if (ptr->data < x)
        {
            if (first)
            {
                first->next = ptr;
                first = first->next;
            }
            else
            {
                first = ptr;
                fhead = first;
            }
            ptr = ptr->next;
            first->next = NULL;
        }
        else if (ptr->data == x)
        {
            if (second)
            {
                second->next = ptr;
                second = second->next;
            }
            else
            {
                second = ptr;
                shead = second;
            }
            ptr = ptr->next;
            second->next = NULL;
        }
        else
        {
            if (third)
            {
                third->next = ptr;
                third = third->next;
            }
            else
            {
                third = ptr;
                thead = third;
            }
            ptr = ptr->next;
            third->next = NULL;
        }
    }
    if (first)
    {
        if (shead)
            first->next = shead;
        else
            first->next = thead;
    }
    if (second)
        second->next = thead;

    head = (fhead ? fhead : (shead ? shead : thead));
    return head;
}