#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        N = n;
        gen(0, 0, "");
        return res;
    }

private:
    int N;
    vector<string> res;
    void gen(int l, int r, string cur)
    {
        if (l == N && r == N)
        {
            res.push_back(cur);
            return;
        }
        if (l < N)
        {
            gen(l + 1, r, cur + '(');
        }
        if (l > r)
        {
            gen(l, r + 1, cur + ')');
        }
    }
};