#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &h)
    {
        int i = 0, j = h.size() - 1, r = 0;
        while (i < j)
        {
            r = max(r, min(h[i], h[j]) * (j - i));
            if (h[i] < h[j])
                i++;
            else
                j--;
        }
        return r;
    }
};