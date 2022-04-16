// Initial Template for C

#include <stdio.h>

// } Driver Code Ends
// User function Template for C

long long int floorSqrt(long long int x)
{
    // Your code goes here
    if (x < 1)
        return 0;
    long long i = 1, j = x, mid;
    while (i < j - 1)
    {
        mid = floor((i + j) / 2);
        if (mid * mid == x)
            return mid;
        else if (mid * mid < x)
            i = mid;
        else
            j = mid;
    }
    return i;
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%ld", &n);

        printf("%ld\n", floorSqrt(n));
    }
    return 0;
}
// } Driver Code Ends