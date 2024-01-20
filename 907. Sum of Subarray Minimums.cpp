#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        const int m = arr.size(), mod = 1e9 + 7;
        stack<int> st;
        vector<int> dp(m, 0);
        for (int i = 0; i < m; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (st.empty())
                dp[i] = (i + 1) * arr[i];
            else
            {
                int prev = st.top();
                dp[i] = dp[prev] + (i - prev) * arr[i];
            }
            st.push(i);
        }

        long r = 0;
        for (auto v : dp)
            r = (r + v) % mod;
        return r;
    }
};