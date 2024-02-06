/*pq
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> r;
        unordered_map<int, int> map;
        for (auto n : nums)
        {
            map[n]++;
        }
        // pair:{freq,num}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto &[key, v] : map)
        {

            pq.push({v, key});
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        while (!pq.empty())
        {
            r.push_back(pq.top().second);
            pq.pop();
        }
        return r;
    }
};
*/
// bucket sort
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int K)
    {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> map;
        vector<int> r;
        for (auto n : nums)
            map[n]++;
        for (auto &[k, v] : map)
        {
            buckets[v].push_back(k);
        }
        for (int i = nums.size(); i >= 0 && K > 0; i--)
        {
            if (!buckets[i].empty())
            {
                r.insert(r.end(), buckets[i].begin(), buckets[i].end());
                K -= buckets[i].size();
            }
        }
        return r;
    }
};