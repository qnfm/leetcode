#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        stack<int> st;
        for (auto &op : operations)
        {
            if (op == "+")
            {
                int p1 = st.top();
                st.pop();
                int p2 = st.top();
                st.pop();
                st.push(p2);
                st.push(p1);
                st.push(p1 + p2);
            }
            else if (op == "D")
            {
                st.push(st.top() << 1);
            }
            else if (op == "C")
            {
                st.pop();
            }
            else
            {
                st.push(stoi(op));
            }
        }
        int r = 0;
        while (!st.empty())
        {
            r += st.top();
            st.pop();
        }
        return r;
    }
};