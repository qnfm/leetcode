#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        for (auto &e : edges)
        {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        return dfs(source, destination);
    }

private:
    unordered_map<int, vector<int>> g;
    unordered_set<int> visited;
    bool dfs(int node, int dest)
    {
        if (node == dest)
            return true;
        visited.insert(node);
        for (auto n : g[node])
        {
            if (!visited.contains(n))
            {
                if (dfs(n, dest))
                    return true;
            }
        }
        return false;
    }
};