#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<long long> dijkstra(int src, int n, vector<vector<int>> adj[])
    {
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();
            if (dist[node] < d)
                continue;
            for (auto i : adj[node])
            {
                if (d + i[1] < dist[i[0]])
                {
                    dist[i[0]] = d + i[1];
                    pq.push({dist[i[0]], i[0]});
                }
            }
        }
        return dist;
    }

public:
    /*
    You are given an integer n denoting the number of nodes of a weighted directed graph. The nodes are numbered from 0 to n - 1.

    You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] denotes that there exists a directed edge from fromi to toi with weight weighti.

    Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

    Return the minimum weight of a subgraph of the graph such that it is possible to reach dest from both src1 and src2 via a set of edges of this subgraph. In case such a subgraph does not exist, return -1.

    A subgraph is a graph whose vertices and edges are subsets of the original graph. The weight of a subgraph is the sum of weights of its constituent edges.
    */
    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        long long minWeight = LLONG_MAX;
        vector<vector<int>> adj[n], revAdj[n];

        for (auto edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            revAdj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long long> distance1 = dijkstra(src1, n, adj),
                          distance2 = dijkstra(src2, n, adj),
                          revDistance = dijkstra(dest, n, revAdj);

        for (int i = 0; i < n; i++)
        {
            if (distance1[i] == LLONG_MAX || distance2[i] == LLONG_MAX || revDistance[i] == LLONG_MAX)
                continue;
            minWeight = min(minWeight, distance1[i] + distance2[i] + revDistance[i]);
        }
        return minWeight == LLONG_MAX ? -1 : minWeight;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, src1, src2, dest;
        cin >> n >> m;

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];

        cin >> src1 >> src2 >> dest;

        Solution obj;
        cout << obj.minimumWeight(n, edges, src1, src2, dest) << endl;
    }

    return 0;
}