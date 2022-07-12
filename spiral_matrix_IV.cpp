#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        next = NULL;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        int rstart = 0, cstart = 0, rend = m - 1, cend = n - 1;
        while (rstart <= rend && cstart <= cend)
        {
            for (int i = cstart; i <= cend; i++)
            {
                if (head)
                {
                    matrix[rstart][i] = head->val;
                    head = head->next;
                }
            }
            rstart++;
            for (int i = rstart; i <= rend; i++)
            {
                if (head)
                {
                    matrix[i][cend] = head->val;
                    head = head->next;
                }
            }
            cend--;
            if (rend >= rstart)
            {
                for (int i = cend; i >= cstart; i--)
                {
                    if (head)
                    {
                        matrix[rend][i] = head->val;
                        head = head->next;
                    }
                }
                rend--;
            }
            if (cend >= cstart)
            {
                for (int i = rend; i >= rstart; i--)
                {
                    if (head)
                    {
                        matrix[i][cstart] = head->val;
                        head = head->next;
                    }
                }
                cstart++;
            }
        }
        return matrix;
    }
};

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct ListNode *head = NULL, *temp = NULL;
        int m, n, l;
        cin >> m >> n >> l;

        for (int i = 0; i < l; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new ListNode(value);
                temp = head;
            }
            else
            {
                temp->next = new ListNode(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        Solution obj;
        vector<vector<int>> matrix = obj.spiralMatrix(m, n, head);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    return (0);
}