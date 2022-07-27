#include <bits/stdc++.h>
using namespace std;

class NumArray
{
    vector<int> nums;
    vector<int> tree;

    void fenwick_tree(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
            add(i, nums[i]);
    }

    void add(int i, int val)
    {
        i++;
        while (i <= tree.size())
        {
            tree[i - 1] += val;
            i += i & (-i); // i = i + LSB(i)
        }
    }

    int prefix_sum(int i)
    {
        int sum = 0;
        i++;
        while (i)
        {
            sum += tree[i - 1];
            i -= i & (-i); // i = i - LSB(i)
        }
        return sum;
    }

public:
    NumArray(vector<int> &nums) : nums(nums), tree(nums.size(), 0)
    {
        fenwick_tree(nums);
    }

    void update(int index, int val)
    {
        add(index, val - nums[index]);
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        return prefix_sum(right) - (left > 0 ? prefix_sum(left - 1) : 0);
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