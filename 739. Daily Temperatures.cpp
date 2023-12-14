#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        vector<int> r(t.size(), 0);
        stack<pair<int, int>> st;

        for (int i = 0; i < t.size(); i++)
        {
            while (!st.empty() && t[i] > st.top().first)
            {
                auto curr = st.top();
                st.pop();
                r[curr.second] = i - curr.second;
            }
            st.push({t[i], i});
        }
        return r;
    }
};