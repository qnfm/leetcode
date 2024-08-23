#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original,
        vector<char>& changed, vector<int>& cost)
    {
        long long r = 0;
        unordered_map<string, int> dict;
        for (int i = 0; i < original.size(); i++) {
            string cur;
            cur += original[i];
            cur += changed[i];
            if (dict.contains(cur))
                dict[cur] = min(dict[cur], cost[i]);
            else
                dict[cur] = cost[i];
        }
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i])
                continue;
            string cur;
            cur += source[i];
            cur += target[i];
            if (!dict.contains(cur))
                return -1;
            r += dict[cur];
        }
        return r;
    }
};
