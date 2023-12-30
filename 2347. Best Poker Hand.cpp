#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        int fmask = 0;
        unordered_map<int, int> rfreq;
        for (int i = 0; i < ranks.size(); i++)
        {
            if (suits[i] == suits[0])
                ++fmask;
            rfreq[ranks[i]]++;
        }
        if (fmask == 5)
            return "Flush";
        for (const auto &[k, v] : rfreq)
        {
            if (v >= 3)
                return "Three of a Kind";
        }
        for (const auto &[k, v] : rfreq)
        {
            if (v == 2)
                return "Pair";
        }
        return "High Card";
    }
};