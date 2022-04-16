// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    class DisjointSet
    {
        vector<int> parent;
        int size;

    public:
        DisjointSet(int x)
        {
            this->size = x;
            parent = vector<int>(x);
            for (int i = 0; i < size; i++)
                parent[i] = i;
        }

        int find(int x)
        {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void merge(int x, int y)
        {
            parent[x] = find(y);
        }
    };

    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        int jobDone = 0, profit = 0, timeSlot;
        DisjointSet ds(n + 1);

        sort(arr, arr + n, [](const Job &j1, const Job &j2)
             { return j1.profit > j2.profit; });

        for (int i = 0; i < n; i++)
        {
            timeSlot = ds.find(min(arr[i].dead, n));
            if (timeSlot > 0)
            {
                jobDone++;
                profit += arr[i].profit;
                ds.merge(timeSlot, timeSlot - 1);
            }
        }
        return {jobDone, profit};
    }
};

// { Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends