#include <bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet
{
    unordered_set<int> s;
    int smallest;

public:
    /*
    You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].

    Implement the SmallestInfiniteSet class:
        > SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
        > int popSmallest() Removes and returns the smallest integer contained in the infinite set.
        > void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
    */
    SmallestInfiniteSet()
    {
        this->s = unordered_set<int>();
        this->smallest = 1;
    }

    int popSmallest()
    {
        int smallestInteger = smallest;
        s.insert(smallest);
        while (s.find(smallest) != s.end())
            smallest++;
        return smallestInteger;
    }

    void addBack(int num)
    {
        if (s.find(num) != s.end())
        {
            smallest = min(smallest, num);
            s.erase(num);
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        SmallestInfiniteSet *obj = new SmallestInfiniteSet();
        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "addBack")
            {
                int num;
                cin >> num;
                obj->addBack(num);
            }
            else if (s == "popSmallest")
            {
                cout << obj->popSmallest() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}