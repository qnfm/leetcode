#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int r = 0, mod = 1e9 + 7;
        unordered_map<int, int> map;

        for (int k = 0; k < arr.size(); k++)
        {
            r = (r + map[target - arr[k]]) % mod;
            for (int j = 0; j < k; j++)
            {
                map[arr[j] + arr[k]]++;
            }
        }
        return r;
    }
};