#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node
{
    int data;
    Node *next;
    Node *random;

    Node(int x)
    {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// } Driver Code Ends
class Solution
{
public:
    Node *copyList(Node *head)
    {
        // Write your code here
        if (!head)
            return NULL;
        unordered_map<Node *, Node *> copy;
        Node *ptr = head;
        while (ptr)
        {
            copy[ptr] = new Node(ptr->data);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr)
        {
            copy[ptr]->next = copy[ptr->next];
            copy[ptr]->random = copy[ptr->random];
            ptr = ptr->next;
        }
        return copy[head];
    }
};

// { Driver Code Starts.

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        int k;
        if (temp->random == NULL)
            k = -1;
        else
            k = temp->random->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data)
{

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
    }
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res)
{

    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL)
    {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2)
        return false;

    temp1 = head;
    temp2 = res;
    map<Node *, Node *> a;
    while (temp1 != NULL)
    {

        if (temp1 == temp2)
            return false;

        if (temp1->data != temp2->data)
            return false;
        if (temp1->random != NULL and temp2->random != NULL)
        {
            if (temp1->random->data != temp2->random->data)
                return false;
        }
        else if (temp1->random != NULL and temp2->random == NULL)
            return false;
        else if (temp1->random == NULL and temp2->random != NULL)
            return false;
        a[temp1] = temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL)
    {

        if (temp1->random != NULL and temp2->random != NULL)
        {
            if (a[temp1->random] != temp2->random)
                return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

int main()
{

    int T, i, n, l, k;
    Node *generated_addr = NULL;
    /*reading input stuff*/
    cin >> T;
    while (T--)
    {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++)
        {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
        for (int i = 0; i < k; i++)
        {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL)
            {
                count++;
                if (count == a - 1)
                    break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL)
            {
                count++;
                if (count == b - 1)
                    break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n)
            {
                tempA->random = tempB;
                temp2A->random = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if (validation(head2, res) && validation(head, res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
} // } Driver Code Ends