#include <bits/stdc++.h>

using namespace std;

int palindromic_substrings(string s)
{
    int palindroms = 0;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; i + j < s.size() && i - j > -1; j++)
            if (s[i + j] != s[i - j])
                break;
            else
                palindroms++;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; i + j + 1 < s.size() && i - j > -1; j++)
            if (s[i + j + 1] != s[i - j])
                break;
            else
                palindroms++;
    return palindroms;
}

int main()
{
    string s;
    getline(cin, s);
    cout << palindromic_substrings(s);
    return 0;
}