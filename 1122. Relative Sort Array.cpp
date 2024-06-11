#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> map;
        for (auto n : arr1)
        {
            ++map[n];
        }
        int i = 0, j = 0;
        while (j < arr2.size())
        {
            while (map[arr2[j]] > 0)
            {
                --map[arr2[j]];
                arr1[i] = arr2[j];
                ++i;
            }
            ++j;
        }
        j = i;
        for (auto &[k, v] : map)
        {
            while (v > 0)
            {
                arr1[i++] = k;
                --v;
            }
        }
        sort(arr1.begin() + j, arr1.end());
        return arr1;
    }
};