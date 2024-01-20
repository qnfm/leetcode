#include <vector>
#include <stack>
using namespace std;
// 907
// typical monotonous increase stack
stack<int> mono_stack(vector<int> &A)
{
    stack<int> st;
    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && st.top() > A[i])
        {
            st.pop();
        }
        st.push(A[i]);
    }
    return st;
}

/*
1
find the previous less element of each element in a vector with O(n) time:
array:
3 7 8 4
ple:
N 3 7 3
ple is the top if not empty
*/
vector<int> prev_less_elem(vector<int> &A)
{
    stack<int> st;
    vector<int> ple(A.size(), -1);
    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && A[st.top()] > A[i])
        {
            st.pop();
        }
        ple[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ple;
}
/*
2
find the next less element of each element in a vector with O(n) time:
array:
3 7 8 4
nle:
N 4 4 N
*/
vector<int> next_less_elem(vector<int> &A)
{
    vector<int> nle;
    stack<int> st;
    for (int i = 0; i < A.size(); i++)
    {
        while (!st.empty() && A[st.top()] > A[i])
        {
            auto less = st.top();
            st.pop();
            nle[less] = i;
        }
        st.push(i);
    }
    return nle;
}