// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
public:
    Node *reverse(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        Node *back = NULL, *front = head->next;
        while (front != NULL)
        {
            head->next = back;
            back = head;
            head = front;
            front = front->next;
        }
        head->next = back;
        return head;
    }
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        // code here
        Node *sum = NULL, *ptr;
        int carry = 0;
        first = reverse(first);
        second = reverse(second);
        while (first != NULL && second != NULL)
        {
            ptr = new Node((first->data + second->data + carry) % 10);
            carry = (first->data + second->data + carry) / 10;
            if (sum == NULL)
                sum = ptr;
            else
            {
                ptr->next = sum;
                sum = ptr;
            }
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            ptr = new Node((first->data + carry) % 10);
            carry = (first->data + carry) / 10;
            if (sum == NULL)
                sum = ptr;
            else
            {
                ptr->next = sum;
                sum = ptr;
            }
            first = first->next;
        }

        while (second != NULL)
        {
            ptr = new Node((second->data + carry) % 10);
            carry = (second->data + carry) / 10;
            if (sum == NULL)
                sum = ptr;
            else
            {
                ptr->next = sum;
                sum = ptr;
            }
            second = second->next;
        }

        if (carry)
        {
            ptr = new Node(carry);
            ptr->next = sum;
            sum = ptr;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends