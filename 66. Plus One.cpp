#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++)
        {
            int sum = (*it) + carry;
            carry = sum / 10;
            *it = sum % 10;
        }
        if (carry == 0)
            return digits;
        vector<int> r(1, 1);
        r.insert(r.end(), digits.begin(), digits.end());
        return r;
    }
};