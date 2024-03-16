#include <string>
using namespace std;
class Solution
{
public:
    int minimumLength(string s)
    {
        int slow = 0, fast = s.size() - 1;
        while (slow < fast && s[slow] == s[fast])
        {
            char c = s[slow];
            while (slow <= fast && s[slow] == c)
            {
                slow++;
            }
            while (slow < fast && s[fast] == c)
            {
                fast--;
            }
        }
        return fast - slow + 1;
    }
};