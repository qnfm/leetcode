#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        istringstream ss(s);
        string cur;
        int r = 0;
        while (ss >> cur)
        {
        }
        return cur.size();
    }
};