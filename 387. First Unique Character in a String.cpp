#include <array>
#include <string>
using namespace std;
class Solution
{
public:
    int firstUniqChar(string s)
    {
        array<int, 26> freq{};
        for (auto c : s)
        {
            freq[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (freq[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};