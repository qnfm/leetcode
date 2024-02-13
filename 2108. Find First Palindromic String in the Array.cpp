#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (auto &s : words)
        {
            int slow = 0, fast = s.size() - 1;
            while (slow < fast && s[slow] == s[fast])
            {
                slow++;
                fast--;
            }
            if (slow == fast || slow == fast + 1)
                return s;
        }
        return "";
    }
};