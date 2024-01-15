#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> r;
        unordered_map<char, pair<int, int>> map;
        for (int i = 0; i < s.size(); i++)
        {
            if (map.contains(s[i]))
            {
                map[s[i]].first = min(map[s[i]].first, i);
                map[s[i]].second = max(map[s[i]].second, i);
            }
            else
                map[s[i]] = {i, i};
        }
        int start = INT_MAX, end = INT_MIN;
        for (int i = 0; i < s.size(); i++)
        {
            auto p = map[s[i]];
            if (start == INT_MAX || end == INT_MIN || (i >= start && i <= end))
            {
                start = min(start, p.first);
                end = max(end, p.second);
            }
            else
            {
                r.push_back(end - start + 1);
                start = p.first, end = p.second;
            }
        }
        r.push_back(end - start + 1);
        return r;
    }
};