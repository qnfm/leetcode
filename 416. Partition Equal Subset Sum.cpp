#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        unordered_set<int> st;
        st.insert(0);
        int sum = 0, half;
        for (auto n : nums)
            sum += n;
        if (sum & 1)
            return false;
        half = sum >> 1;
        for (auto n : nums)
        {
            unordered_set<int> cur;
            for (auto elem : st)
            {
                int s = elem + n;
                if (s == half)
                    return true;
                cur.insert(s);
                cur.insert(elem);
            }
            st = cur;
        }
        return false;
    }
};