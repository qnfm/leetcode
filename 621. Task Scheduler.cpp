#include <array>
#include <vector>
using namespace std;
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        array<int, 26> freq{};
        int maxf = INT_MIN;
        for (auto c : tasks)
        {
            freq[c - 'A']++;
            maxf = max(maxf, freq[c - 'A']);
        }
        int r = (maxf - 1) * (n + 1);
        for (auto f : freq)
        {
            if (f == maxf)
            {
                ++r;
            }
        }
        return r < tasks.size() ? tasks.size() : r;
    }
};