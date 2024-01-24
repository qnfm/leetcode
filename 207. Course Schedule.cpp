#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        for (auto &pre : prerequisites)
            map[pre[0]].push_back(pre[1]);
        for (int course = 0; course < numCourses; course++)
        {
            if (!dfs(course))
                return false;
        }
        return true;
    }

private:
    unordered_map<int, vector<int>> map;
    unordered_set<int> visited;
    bool dfs(int course)
    {
        if (visited.contains(course))
            return false;
        auto &prereq = map[course];
        if (prereq.empty())
            return true;
        visited.insert(course);
        for (auto pre : prereq)
            if (!dfs(pre))
                return false;
        prereq.clear();
        visited.erase(course);
        return true;
    }
};