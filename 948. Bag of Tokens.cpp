#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        // up->  <-down
        int left = 0, right = tokens.size() - 1;
        int r = 0;
        while (left <= right)
        {
            if (power >= tokens[left])
            {
                r++;
                power -= tokens[left];
                left++;
            }
            else
            {
                if (r > 0 && left < right)
                {
                    power += tokens[right];
                    right--;
                    r--;
                }
                else
                    return r;
            }
        }
        return r;
    }
};