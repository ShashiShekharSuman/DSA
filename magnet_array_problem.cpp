#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        void nullPoints(int n, double magnets[], double getAnswer[])
    {
        // Your code goes here
        double start, end, mid, force;
        for (int i = 0; i < n-1; i++) {
            start = magnets[i], end = magnets[i+1];
            while(start < end) {
                mid = start + (end - start)/2;
                force = 0;
                for (int j = 0; j < n; j++) force += 1/(magnets[j]-mid);
                if (abs(force) < 1e-9) {
                    getAnswer[i] = mid;
                    break;
                }
                else if (force < 0) start = mid;
                else end = mid;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        double magnets[n], getAnswer[n];
        for(int i=0;i<n;i++)
        cin>>magnets[i];
        Solution ob;
        ob.nullPoints(n, magnets, getAnswer);
        
        for(int i=0; i<n-1; i++)
            printf("%0.2lf ",getAnswer[i]);
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends