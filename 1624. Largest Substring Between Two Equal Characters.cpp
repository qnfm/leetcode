#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        unordered_map<char, vector<int>> map;
        for (int i = 0; i < s.size(); i++)
            map[s[i]].push_back(i);
        int r = -1;
        for (auto &[k, v] : map)
        {
            if (v.size() >= 2)
            {
                sort(v.begin(), v.end());
                r = max(r, *v.rbegin() - *v.begin() - 1);
            }
        }
        return r;
    }
};