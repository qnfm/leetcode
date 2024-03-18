#include <utility>
#include <queue>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);

        for (auto it : flights)
            adj[it[0]].push_back({it[1], it[2]});

        vector<int> dist(n, 1e9);

        //<stops, node, dist> Note: if we take dist as first then ans will be wrong. why?
        // remember: min cost with atmost K stops
        queue<pair<int, pair<int, int>>> q; // no need to use min-heap

        q.push({0, {src, 0}});
        dist[src] = 0;

        while (!q.empty())
        {
            int dis = q.front().first;
            int node = q.front().second.first;
            int stops = q.front().second.second;

            q.pop();

            if (stops > k)
                continue;

            for (auto it : adj[node])
            {
                if (stops <= k && dis + it.second < dist[it.first])
                {
                    dist[it.first] = dis + it.second;
                    q.push({dis + it.second, {it.first, stops + 1}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};