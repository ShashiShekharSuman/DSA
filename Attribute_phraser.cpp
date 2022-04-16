#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, string> attr_map;
    string line, query, nest, value;
    int n, q;
    cin >> n >> q;
    cin.ignore();
    while (n--)
    {
        int i = 1, j, k;
        getline(cin, line);
        if (line[i] != '/')
        {
            while (line[i] != ' ' && line[i] != '>')
                i++;
            if (nest != "")
                nest += '.';
            nest += line.substr(1, i - 1);
            while (line[i] != '>')
            {
                j = i + 1;
                while (line[i] != '=')
                    i++;
                k = i - 2;
                i += 4;
                while (line[i] != '"')
                    i++;
                attr_map[nest + '~' + line.substr(j, k - j + 1)] = line.substr(k + 5, i - k - 5);
                i++;
            }
        }
        else if (nest.find(line.substr(i + 1, line.length() - i - 2)))
        {
            nest = nest.substr(0, nest.find(line.substr(i + 1, line.length() - i - 2)) - 1);
        }

        else
            nest = "";
    }
    while (q--)
    {
        getline(cin, query);
        value = attr_map[query];
        if (value == "")
            cout << "Not Found!" << endl;
        else
            cout << value << endl;
    }
    return 0;
}
