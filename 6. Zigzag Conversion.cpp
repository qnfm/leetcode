#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;
        vector<string> z(numRows, "");
        string r;
        bool edge = true;
        for (int i = 0, j = 0; i < s.size(); i++)
        {
            z.at(j) += s.at(i);
            if (j == numRows - 1 || j == 0)
                edge = !edge;
            if (edge)
                j--;
            else
                j++;
        }
        for (auto &str : z)
            r += str;
        return r;
    }
};