#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (j < arr.size()) {
            if (arr[j] & 1)
                ++cnt;
            if (j - i < 2) {
                ++j;
            } else {
                if (cnt == 3)
                    return true;
                cnt += arr[i] & 1 ? -1 : 0;
                i++;
                j++;
            }
        }
        return false;
    }
};
