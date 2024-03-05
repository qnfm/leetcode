#include <array>
#include <string>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        array<int, 128> ms{}, mt{};
        for (int i = 0; i < s.size(); i++)
        {
            if (ms[s[i]] != mt[t[i]])
                return false;
            ms[s[i]] = i + 1;
            mt[t[i]] = i + 1;
        }
        return true;
    }
};