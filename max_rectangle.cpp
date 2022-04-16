#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
public:
    vector<int> nextSmallest(vector<int> arr)
    {
        auto n = arr.size();
        vector<int> nextIndex(n, n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                nextIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return nextIndex;
    }

    vector<int> prevSmallest(vector<int> arr)
    {
        auto n = arr.size();
        vector<int> prevIndex(n, -1);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[i] < arr[s.top()])
            {
                prevIndex[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        return prevIndex;
    }

    void maxArea(vector<int> arr, int &max)
    {
        auto n = arr.size();
        vector<int> nextIndex = nextSmallest(arr),
                    prevIndex = prevSmallest(arr);

        for (int i = 0; i < n; i++)
        {
            if ((nextIndex[i] - prevIndex[i] - 1) * arr[i] > max)
                max = arr[i] * (nextIndex[i] - prevIndex[i] - 1);
        }
    }

    int maxArea(int M[MAX][MAX], int n, int m)
    {
        // Your code here
        int max = 0;
        vector<int> arr(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j])
                    arr[j]++;
                else
                    arr[j] = 0;
            }
            maxArea(arr, max);
        }
        return max;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends