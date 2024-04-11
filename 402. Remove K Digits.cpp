#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (auto d : num)
        {
            while (!st.empty() && k > 0 && st.top() > d)
            {
                st.pop();
                --k;
            }
            st.push(d);
        }
        while (!st.empty() && k > 0)
        {
            st.pop();
            --k;
        }

        string r;
        while (!st.empty())
        {
            r += st.top();
            st.pop();
        }
        reverse(r.begin(), r.end());
        auto pos = r.find_first_not_of('0');
        return (pos == string::npos) ? "0" : r.substr(pos);
    }
};