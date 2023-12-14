#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, double>> ps(position.size(), {0, 0});
        for (int i = 0; i < position.size(); i++)
        {
            ps[i] = {position[i], double(target - position[i]) / speed[i]};
        }
        sort(ps.begin(), ps.end(),
             [&](auto &a, auto &b)
             { return a.first > b.first; });
        stack<double> st;
        st.push(ps[0].second);
        for (int i = 1; i < ps.size(); i++)
        {
            if (st.top() < ps[i].second)
                st.push(ps[i].second);
        }
        return st.size();
    }
};