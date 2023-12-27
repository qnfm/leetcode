#include <string>
#include <vector>
#include <stack>
// #include <pair>
using namespace std;
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        stack<pair<char, int>> st;
        st.push({colors[0], neededTime[0]});
        int r = 0;
        for (int i = 1; i < colors.size(); i++)
        {
            if (!st.empty())
            {
                if (st.top().first == colors[i])
                {
                    if (st.top().second < neededTime[i])
                    {
                        r += st.top().second;
                        st.pop();
                        st.push({colors[i], neededTime[i]});
                    }
                    else
                        r += neededTime[i];
                }
                else
                {
                    st.pop();
                    st.push({colors[i], neededTime[i]});
                }
            }
            else
                st.push({colors[i], neededTime[i]});
        }

        return r;
    }
};