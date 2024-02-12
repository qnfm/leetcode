#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        const int N = heights.size();
        stack<pair<int, int>> st;
        int r = 0;
        for (int i = 0; i < N; i++)
        {
            int start = i;
            while (!st.empty() && heights[i] < st.top().second)
            {
                r = max(r, st.top().second * (i - st.top().first));
                start = st.top().first;
                st.pop();
            }
            st.push({start, heights[i]});
        }

        while (!st.empty())
        {
            r = max(r, (N - st.top().first) * st.top().second);
            st.pop();
        }
        return r;
    }
};