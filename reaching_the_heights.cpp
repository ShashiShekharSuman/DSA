
#include <bits/stdc++.h>
using namespace std;

vector<int> reaching_height(int n, int a[]);

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> v;
        v = reaching_height(n, a);

        if (v.size() == 1 and v[0] == -1)
        {
            cout << "Not Possible\n";
        }
        else
        {
            for (int i : v)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends

// User function Template for C++
/*
The teacher gives a mental ability question to Raju. The question is as follows:-

Raju is in an elevator. Given by his teacher is an array of size N which denotes the number of floors and has a 1 based indexing. The elevator starts from the ground and moves up and down, X and Y floors respectively. There is a code used in the elevator according to which it moves up X floors given at odd indexes of the array and moves down Y floors given at even indexes of the array. He is asked to go to the highest floor possible. Help him to sort the array such that he reaches the highest floor after traversing the whole array from starting till the end, without skipping any index.

He always prefers to move more number of floors up and less number of floors down. Once he gets into the elevator, the elevator should not reach the ground again, if it does print Not Possible.
*/
vector<int> reaching_height(int n, int a[])
{
    // Complete the function
    sort(a, a + n);
    if (a[0] == a[n - 1] && n != 1)
        return {-1};

    vector<int> result(n);
    for (int i = 0, j = n - 1, k = 0; k < n; k++)
        if (k & 1)
            result[k] = a[i++];
        else
            result[k] = a[j--];

    return result;
}
