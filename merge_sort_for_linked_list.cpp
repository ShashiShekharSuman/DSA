#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

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

// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node *merge(Node *firstHalf, Node *secondHalf)
    {
        if (firstHalf == NULL)
            return secondHalf;
        else if (secondHalf == NULL)
            return firstHalf;
        else
        {
            Node *result = NULL;
            if (firstHalf->data <= secondHalf->data)
            {
                result = firstHalf;
                result->next = merge(firstHalf->next, secondHalf);
            }
            else
            {
                result = secondHalf;
                result->next = merge(firstHalf, secondHalf->next);
            }
            return result;
        }
    }

    Node *mergeSort(Node *head)
    {
        if (head->next == NULL)
            return head;

        Node *slow = head, *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
        Node *firstHalf = head, *secondHalf = slow->next;
        slow->next = NULL;

        firstHalf = mergeSort(firstHalf);
        secondHalf = mergeSort(secondHalf);
        head = merge(firstHalf, secondHalf);
        return head;
        // your code here
    }
};

// { Driver Code Starts.

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
} // } Driver Code Ends