#include <cmath>
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left{}, right = sqrt(c);

        while (left <= right) {
            const long long sum = left * left + right * right;

            if (sum == c)
                return true;

            if (sum > c)
                --right;
            else
                ++left;
        }

        return false;
    }
};
