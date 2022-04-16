#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
private:
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        this->l = list<pair<int, int>>();
        this->cache = unordered_map<int, list<pair<int, int>>::iterator>();
        this->capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key)
    {
        // your code here
        if (cache.find(key) == cache.end())
            return -1;
        l.splice(l.begin(), l, cache[key]);
        return cache[key]->second;
    }

    // Function for storing key-value pair.
    void set(int key, int value)
    {
        // your code here
        if (cache.find(key) != cache.end())
        {
            l.splice(l.begin(), l, cache[key]);
            cache[key]->second = value;
            return;
        }

        if (l.size() == capacity)
        {
            auto dkey = l.back().first;
            l.pop_back();
            cache.erase(dkey);
        }

        l.push_front({key, value});
        cache[key] = l.begin();
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

// #include <iostream>
// #include <unordered_map>

// using namespace std;

// class LRUCache
// {
// private:
//     class Node
//     {
//     public:
//         int key, value;
//         Node *next, *prev;
//         Node(int key, int value)
//         {
//             this->key = key;
//             this->value = value;
//             this->next = NULL;
//             this->prev = NULL;
//         }
//     };

//     Node *head, *tail;
//     int capacity;
//     unordered_map<int, Node *> cache;

//     void push_front(Node *node)
//     {
//         if (head)
//         {
//             head->prev = node;
//             node->next = head;
//         }
//         if (!tail)
//             tail = node;
//         head = node;
//     }

//     void pop(Node *node)
//     {
//         if (node->prev)
//             node->prev->next = node->next;
//         if (node->next)
//             node->next->prev = node->prev;
//         if (head == node)
//             head = node->next;
//         if (tail == node)
//             tail = node->prev;
//     }

// public:
//     // Constructor for initializing the cache capacity with the given value.
//     LRUCache(int cap)
//     {
//         // code here
//         this->capacity = cap;
//         head = NULL;
//         tail = NULL;
//         cache = unordered_map<int, Node *>();
//     }

//     // Function to return value corresponding to the key.
//     int get(int key)
//     {
//         // your code here
//         if (cache.find(key) == cache.end())
//             return -1;
//         Node *node = cache[key];
//         pop(node);
//         push_front(node);
//         return node->value;
//     }

//     // Function for storing key-value pair.
//     void set(int key, int value)
//     {
//         // your code here
//         if (cache.find(key) == cache.end())
//         {
//             Node *node = new Node(key, value);
//             cache[key] = node;
//             push_front(node);
//             if (cache.size() > capacity)
//             {
//                 cache.erase(tail->key);
//                 pop(tail);
//             }
//         }
//         else
//         {
//             Node *node = cache[key];
//             node->value = value;
//             pop(node);
//             push_front(node);
//         }
//     }
// };