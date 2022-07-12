#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

        > The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
        > The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
    Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.
    */
    bool canChange(string start, string target)
    {
        int i = 0, j = 0;
        // string s = "", t = "", ;
        while (i < start.size() && j < target.size())
        {
            while (i < start.size() && start[i] == '_')
                i++;
            while (j < target.size() && target[j] == '_')
                j++;
            if (i == start.size() && j == target.size())
                break;
            if (i < start.size() && j < target.size())
            {
                if (start[i] != target[j])
                    return false;
                if (start[i] == 'L' && i < j)
                    return false;
                if (start[i] == 'R' && i > j)
                    return false;
                i++;
                j++;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string start, target;
        cin >> start >> target;
        Solution obj;
        cout << obj.canChange(start, target) << endl;
    }
    return 0;
}