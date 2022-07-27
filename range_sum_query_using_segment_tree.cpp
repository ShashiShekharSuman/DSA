#include <bits/stdc++.h>
using namespace std;

class NumArray
{

    vector<int> tree;
    int n;

    void segment_tree(int i, int l, int r, vector<int> &nums)
    {
        if (r - l == 1)
        {
            this->tree[i] = nums[l];
            return;
        }
        int mid = l + (r - l) / 2;
        segment_tree(2 * i + 1, l, mid, nums);
        segment_tree(2 * i + 2, mid, r, nums);
        tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
    }

    void update(int i, int l, int r, int index, int val)
    {
        if (index < l || index >= r)
            return;
        if (r - l == 1)
        {
            this->tree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        update(2 * i + 1, l, mid, index, val);
        update(2 * i + 2, mid, r, index, val);
        tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
    }

    int query(int i, int l, int r, int left, int right)
    {
        if (right <= l || left >= r)
            return 0;
        if (left <= l && right >= r)
            return tree[i];
        int mid = l + (r - l) / 2;
        return query(2 * i + 1, l, mid, left, right) + query(2 * i + 2, mid, r, left, right);
    }

public:
    NumArray(vector<int> &nums)
    {
        this->n = nums.size();
        this->tree = vector<int>(4 * n, 0);
        segment_tree(0, 0, n, nums);
    }

    void update(int index, int val)
    {
        update(0, 0, n, index, val);
    }

    int sumRange(int left, int right)
    {
        return query(0, 0, n, left, right + 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        NumArray *obj = new NumArray(nums);
        while (q--)
        {
            string query;
            int a, b;
            cin >> query >> a >> b;
            if (query == "update")
                obj->update(a, b);
            else
                cout << obj->sumRange(a, b) << endl;
        }
    }
}