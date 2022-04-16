#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int fuel = 0, index = 0, required = 0;
        for (int i = 0; i < n; i++)
        {
            fuel += p[i].petrol;
            if (fuel < p[i].distance)
            {
                required += p[i].distance - fuel;
                fuel = 0;
                index = (i + 1) % n;
            }
            else
                fuel -= p[i].distance;
        }
        if (fuel - required < 0)
            return -1;
        return index;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}
// } Driver Code Ends