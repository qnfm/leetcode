#include <vector>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (auto str : strs)
        {
            array<int, 26> cur{};
            for (auto c : str)
                cur[c - 'a']++;
            string enc;
            for (int i = 0; i < 26; i++)
                if (cur[i])
                    enc += to_string(i) + "#" + to_string(cur[i]);
            map[enc].push_back(str);
        }
        vector<vector<string>> r;
        for (auto &[k, v] : map)
            r.push_back(v);
        return r;
    }
};