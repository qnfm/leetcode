#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n1, n2;
        for (auto c : tokens)
        {
            if (c == "+" || c == "-" || c == "*" || c == "/")
            {
                n2 = st.top();
                st.pop();
                n1 = st.top();
                st.pop();
                if (c == "+")
                    st.push(n1 + n2);
                if (c == "-")
                    st.push(n1 - n2);
                if (c == "*")
                    st.push(n1 * n2);
                if (c == "/")
                    st.push(n1 / n2);
            }
            else
                st.push(stoi(c));
        }
        return st.top();
    }

private:
    stack<int> st;
};