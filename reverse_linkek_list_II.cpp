#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = NULL;
    }

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }

    ListNode(int val, ListNode *next)
    {
        this->val = val;
        this->next = next;
    }
};

class List
{
public:
    ListNode *head;

    List()
    {
        this->head = NULL;
    }

    void print();
    void push_back(int);
};

void List::print()
{
    ListNode *ptr = this->head;
    cout << "head";
    while (ptr != NULL)
    {
        cout << " --> " << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}

void List::push_back(int data)
{
    if (head == NULL)
    {
        ListNode *new_node = new ListNode(data);
        head = new_node;
    }
    else
    {
        ListNode *ptr = this->head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ListNode *new_node = new ListNode(data);
        ptr->next = new_node;
    }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *reverse(ListNode *head, int index, int right)
    {
        if (!head || !head->next)
            return head;
        ListNode *ptr = head, *front = head->next, *back = NULL;
        while (index < right)
        {
            ptr->next = back;
            back = ptr;
            ptr = front;
            front = front->next;
            index++;
        }
        ptr->next = back;
        head->next = front;
        return ptr;
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *ptr = head, *back = NULL;
        int index = 1;
        while (index < left)
        {
            back = ptr;
            ptr = ptr->next;
            index++;
        }
        if (back)
            back->next = reverse(ptr, index, right);
        else
            head = reverse(ptr, index, right);
        return head;
    }
};

int main()
{

    int t;
    cin >> t;
    getchar();

    while (t--)
    {
        int n, data, left, right;
        List list;
        cin >> n;
        while (n--)
        {
            cin >> data;
            list.push_back(data);
        }
        cin >> left >> right;
        Solution obj;
        list.head = obj.reverseBetween(list.head, left, right);
        list.print();
        cout << endl;
    }

    return 0;
}
