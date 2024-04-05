#include <string>
using namespace std;
class Solution
{
public:
    string makeGood(string s)
    {
        if (s.size() < 2)
            return s;
        auto last = s.end();
        auto sz = s.size();
        for (auto it = s.begin(); it != last - 1; ++it)
        {
            if (abs(*(it) - *(it + 1)) == 32)
            {
                s.erase(it, it + 2);
            }
        }
        if (sz == s.size())
            return s;
        return makeGood(s);
    }
};