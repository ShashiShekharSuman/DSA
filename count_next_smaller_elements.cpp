#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void merge(vector<pair<int, int>> &indexedNums, int start, int mid, int end, vector<int> &nextSmallerCount)
    {
        pair<int, int> a[end - start];
        int i = start, j = mid, k = 0;
        while (i < mid && j < end)
        {
            if (indexedNums[i].first > indexedNums[j].first)
            {
                nextSmallerCount[indexedNums[i].second] += end - j;
                a[k++] = indexedNums[i++];
            }
            else
                a[k++] = indexedNums[j++];
        }
        while (i < mid)
            a[k++] = indexedNums[i++];
        while (j < end)
            a[k++] = indexedNums[j++];
        for (int i = start; i < end; i++)
            indexedNums[i] = a[i - start];
    }

    void mergeSort(vector<pair<int, int>> &indexedNums, int start, int end, vector<int> &nextSmallerCount)
    {
        if (end - start == 1)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(indexedNums, start, mid, nextSmallerCount);
        mergeSort(indexedNums, mid, end, nextSmallerCount);
        merge(indexedNums, start, mid, end, nextSmallerCount);
    }

public:
    /*
    You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
    */
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> nextSmallerCount(nums.size(), 0);
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++)
            indexedNums.push_back({nums[i], i});
        mergeSort(indexedNums, 0, nums.size(), nextSmallerCount);
        return nextSmallerCount;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        Solution obj;
        vector<int> result = obj.countSmaller(nums);
        for (auto i : result)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}