#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        string r;
        unordered_map<char, int> freq;
        for (auto c : s)
            freq[c]++;
        vector<pair<char, int>> pairs;
        for (auto &[k, v] : freq)
            pairs.push_back({k, v});
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
             { return a.second > b.second; });
        for (auto &p : pairs)
        {
            string cur(p.second, p.first);
            r.insert(r.end(), cur.begin(), cur.end());
        }
        return r;
    }
};