#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;
        auto sz = s.size();
        for (int i = 0; i < sz; ++i)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    s[i] = '#';
                }
                else
                    st.pop();
            }
        }
        while (!st.empty())
        {
            s[st.top()] = '#';
            st.pop();
        }
        string r;
        for (auto c : s)
        {
            if (c != '#')
                r.push_back(c);
        }
        return r;
    }
};