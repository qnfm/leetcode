#include <array>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        array<int, 2001> fre{};
        for (auto v : arr)
        {
            fre[v + 1000]++;
        }
        unordered_set<int> set;
        for (auto v : fre)
        {
            if (v != 0)
            {
                if (set.contains(v))
                    return false;
                set.insert(v);
            }
        }
        return true;
    }
};