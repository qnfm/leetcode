#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
            map[t[i]]--;
        }
        for (auto &[k, v] : map)
        {
            if (v != 0)
                return false;
        }
        return true;
    }
};