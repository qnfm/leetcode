#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto &pre : prerequisites)
            map[pre[0]].push_back(pre[1]);
        for (int i = 0; i < numCourses; i++)
        {
            if (!dfs(i))
                return vector<int>();
        }
        return r;
    }

private:
    unordered_map<int, vector<int>> map;
    unordered_set<int> visited;
    unordered_set<int> visiting;
    vector<int> r;
    bool dfs(int i)
    {
        if (visiting.contains(i))
            return false;
        if (visited.contains(i))
            return true;
        visiting.insert(i);
        auto &pre = map[i];
        for (auto p : pre)
        {
            if (!dfs(p))
                return false;
        }
        visiting.erase(i);
        visited.insert(i);
        r.push_back(i);
        return true;
    }
};