#include <string>
using namespace std;
class Solution
{
public:
    int secondHighest(string s)
    {
        int first = -1, second = -1;
        for (const auto c : s)
        {
            int cur = c - '0';
            if (isdigit(c))
            {
                if (cur > first)
                {
                    second = first;
                    first = cur;
                }
                else if (cur != first && cur > second)
                {
                    second = cur;
                }
            }
        }
        return second;
    }
};