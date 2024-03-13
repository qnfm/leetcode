#include <string>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int ones = 0;
        for (auto c : s)
            if (c == '1')
                ones++;
        ones--;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < ones)
                s[i] = '1';
            else
                s[i] = '0';
        }
        s.back() = '1';
        return s;
    }
};