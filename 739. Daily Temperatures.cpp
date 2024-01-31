#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        stack<int> st;
        vector<int> r(t.size());
        for (int i = 0; i < t.size(); i++)
        {
            while (!st.empty() && t[st.top()] < t[i])
            {
                auto cur = st.top();
                st.pop();
                r[cur] = i - cur;
            }
            st.push(i);
        }
        return r;
    }
};