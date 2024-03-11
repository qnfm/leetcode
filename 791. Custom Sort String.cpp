#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> map;
        for (auto c : s)
            map[c]++;
        string r;
        int i;
        for (int i = 0; i < order.size() && i < s.size(); i++)
        {
            if (map[order[i]] > 0)
            {
                r.append(map[order[i]], order[i]);
                map[order[i]] = 0;
            }
        }
        if (i < s.size())
        {
            for (auto &[k, v] : map)
            {
                if (v > 0)
                {
                    r.append(v, k);
                }
            }
        }
        return r;
    }
};