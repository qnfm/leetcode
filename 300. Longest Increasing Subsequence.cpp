#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> st;
        st.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > st.back())
                st.push_back(nums[i]);
            else
            {
                int lo = 0, hi = st.size() - 1, mid;
                bool flag = false;
                while (lo < hi)
                {
                    mid = lo + ((hi - lo) >> 1);
                    if (st[mid] == nums[i])
                    {
                        flag = true;
                        break;
                    }
                    else if (st[mid] > nums[i])
                        hi = mid;
                    else
                        lo = mid + 1;
                }
                if (flag || lo < st.size())
                {
                    mid = flag ? mid : lo;
                    st[mid] = nums[i];
                }
            }
        }
        return st.size();
    }
};