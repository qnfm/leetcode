#include <string>
#include <sstream>
using namespace std;
// class Solution
// {
// public:
//     int lengthOfLastWord(string s)
//     {
//         istringstream ss(s);
//         string cur;
//         int r = 0;
//         while (ss >> cur)
//         {
//         }
//         return cur.size();
//     }
// };

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int r = 0, tail = s.size() - 1;
        while (tail >= 0 && s[tail] == ' ')
            --tail;
        while (tail >= 0 && s[tail] != ' ')
        {
            ++r;
            --tail;
        }
        return r;
    }
};