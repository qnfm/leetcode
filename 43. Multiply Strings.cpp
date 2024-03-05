#include <string>
using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int r = 0;
        for (auto c : num2)
            r = 10 * r + (c - '0') *
    }
};