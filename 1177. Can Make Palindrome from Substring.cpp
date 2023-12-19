#include <vector>
#include <string>
#include <bit>
using namespace std;
class Solution
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries)
    {
        vector<int> prefix(1);
        vector<bool> r;
        int sum = 0;
        for (const auto c : s)
        {
            sum ^= 1 << (c - 'a');
            prefix.push_back(sum);
        }

        for (const auto &query : queries)
        {

            int numone = popcount((unsigned)(prefix[query[1] + 1] ^ prefix[query[0]]));
            r.push_back(query[2] >= numone / 2);
        }
        return r;
    }
};