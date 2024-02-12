#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int start = 0, end = 0, r = 0;
        unordered_set<char> set;
        while (end < s.size())
        {
            while (set.contains(s[end]))
            {
                set.erase(s[start++]);
            }
            r = max(r, end - start + 1);
            set.insert(s[end]);
            end++;
        }
        return r;
    }
};