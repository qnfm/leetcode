#include <string>
#include <array>
using namespace std;
class Solution
{
public:
    bool isFascinating(int n)
    {
        string r = to_string(n) + to_string(n << 1) + to_string(n * 3);
        if (r.size() != 9)
            return false;
        array<int, 9> fre{0};
        for (auto c : r)
        {
            if (c == '0')
                return false;
            fre[c - '1']++;
            if (fre[c - '1'] > 1)
                return false;
        }
        return true;
    }
};