#include <array>
#include <vector>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        // if(trust.size() == 0) return -1;
        int cand = -1;
        // {in - out}
        array<int, 1001> freq{};
        for (auto &t : trust)
        {
            freq[t[0]]--;
            freq[t[1]]++;
        }
        int diff = n - 1;
        for (int i = 1; i < 1001; i++)
        {
            if (freq[i] == diff)
            {
                cand = i;
                break;
            }
        }
        return cand;
    }
};