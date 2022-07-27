#include <bits/stdc++.h>
using namespace std;

int LSB(int n)
{
    return n & (-n);
}

int MSB(int n)
{
    return
}

int LSUB(int n)
{
    if (!(n & (n + 1)))
        return -1;
    return LSB(~n);
}

int MSUB(int n)
{
}

int unsetLSB(int n)
{
    return n & (n - 1);
}

int setLUSB(int n)
{
    if (!(n & (n + 1)))
        return n;
    return n | (n + 1);
}

int setMUSB(int n)
{
}

int unsetMSB(int n)
{
}

int setBits(int n)
{
}

int main()
{
    string s;
    int n;
    cin >> s >> n;
    switch (s)
    {
    case "LSB":
    case "MSB":
    case "unsetLSB":
    case "setLUSB":
    case "unsetMSB":
    case "setMUSB":
    case "setBits":
    }
    return 0;
}