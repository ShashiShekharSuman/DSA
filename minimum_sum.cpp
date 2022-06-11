#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{

    string add(string number1, string number2)
    {
        if (!number1.size())
            return number2;
        if (!number2.size())
            return number1;

        string sum = "";
        int digitSum, carry = 0, i = number1.size() - 1, j = number2.size() - 1;
        while (i >= 0 && j >= 0)
        {
            digitSum = (number1[i] - '0') + (number2[j] - '0') + carry;
            if (digitSum == 0)
                break;
            sum += (char)((digitSum % 10) + '0');
            carry = digitSum / 10;
            i--;
            j--;
        }
        while (i >= 0)
        {
            digitSum = (number1[i--] - '0') + carry;
            if (digitSum == 0)
                break;
            sum += (char)((digitSum % 10) + '0');
            carry = digitSum / 10;
        }
        while (j >= 0)
        {
            digitSum = (number2[j--] - '0') + carry;
            if (digitSum == 0)
                break;
            sum += (char)((digitSum % 10) + '0');
            carry = digitSum / 10;
        }
        if (carry)
            sum += (char)(carry + '0');
        reverse(sum.begin(), sum.end());
        return sum;
    }

public:
    string solve(int arr[], int n)
    {
        // code here
        string number1 = "", number2 = "";
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                number1 += (char)(arr[i] + '0');
            else
                number2 += (char)(arr[i] + '0');
        }
        return add(number1, number2);
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
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends