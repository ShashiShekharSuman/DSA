#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMovesToMakePalindrome(string s)
    {
        int len = s.size(), minSwaps = 0;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] == s[len - i - 1])
                continue;
            auto j = i + 1, pos = i;
            while (j < len - i - 1 && s[j] != s[len - i - 1])
                j++;
            if (j == len - i - 1)
            {
                auto k = i--;
                while (k < j)
                    swap(s[k++], s[j--]);
            }
            else
                while (j != i)
                {
                    swap(s[j], s[j-- - 1]);
                    minSwaps++;
                }
        }
        return minSwaps;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.minMovesToMakePalindrome(s);
        cout << ans << "\n";
    }
    return 0;
}