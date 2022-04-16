#include <iostream>
#include <vector>

using namespace std;

int pass = 1;

int partition(vector<int> &v, int const begin, int const end)
{
    int pivot = v[end];
    int i = begin - 1;
    for (int j = begin; j <= end; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[end]);
    for (auto i : v)
        cout << i << "\t";
    cout << endl;
    return i + 1;
}

void quick_sort(vector<int> &v, int const begin, int const end)
{
    if (begin >= end)
        return;
    cout << "Pass " << pass++ << ":" << endl;
    int pivot = partition(v, begin, end);
    quick_sort(v, begin, pivot - 1);
    quick_sort(v, pivot + 1, end);
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
    quick_sort(vect, 0, vect.size() - 1);
    return 0;
}