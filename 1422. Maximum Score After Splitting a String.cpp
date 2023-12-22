#include <string>
using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int cur = 0;
            string a = s.substr(0, i + 1);
            for (const auto &c : a)
                if (c == '0')
                    ++cur;
            a = s.substr(i + 1);
            for (const auto &c : a)
                if (c == '1')
                    ++cur;
            if (a == "")
                cur = 0;
            sum = max(sum, cur);
        }
        return sum;
    }
};