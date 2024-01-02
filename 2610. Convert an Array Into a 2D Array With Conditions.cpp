#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        vector<vector<int>> r;
        unordered_map<int, int> freq;
        for (const auto n : nums)
            freq[n]++;
        while (!freq.empty())
        {
            vector<int> tmp;
            for (auto it = freq.begin(); it != freq.end();)
            {
                tmp.push_back(it->first);
                it->second--;
                if (it->second == 0)
                    it = freq.erase(it);
                else
                    ++it;
            }
            r.push_back(tmp);
        }
        return r;
    }
};