#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        const int n = height.size();
        vector<int> left(n), right(n);
        int curl = 0, curr = 0, r = 0;
        for (int i = 1, j = n - 2; i < n && j >= 0; j--, i++)
        {
            left[i] = max(curl, height[i - 1]);
            curl = left[i];
            right[j] = max(curr, height[j + 1]);
            curr = right[j];
        }

        for (int i = 1; i < n - 1; i++)
        {
            int hei = min(left[i], right[i]);
            int del = hei - height[i];
            if (del <= 0)
                continue;
            r += del;
        }
        return r;
    }
};