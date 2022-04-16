#include <iostream>
#include <vector>

using namespace std;
int pass = 1;

void merge(vector<int> &v, int const begin, int const mid, int end)
{
    vector<int> left, right, sorted_vector;
    for (int i = begin; i <= end; i++)
    {
        if (i <= mid)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    int i = 0, j = 0, k = begin;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            v[k] = left[i];
            i++;
        }
        else
        {
            v[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left.size())
    {
        v[k] = left[i];
        i++;
        k++;
    }
    while (j < right.size())
    {
        v[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &v, int const begin, int const end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    merge_sort(v, begin, mid);
    merge_sort(v, mid + 1, end);
    merge(v, begin, mid, end);
    cout << "Pass " << pass++ << ":" << endl;
    for (auto i : v)
        cout << i << "\t";
    cout << endl;
}

int main()
{
    int n;
    vector<int> vect;
    cout << "Enter no of elements: ";
    cin >> n;
    cout << "Enter " << n << " numbers: ";
    while (n--)
    {
        int element;
        cin >> element;
        vect.push_back(element);
    }
    merge_sort(vect, 0, vect.size() - 1);
    return 0;
}