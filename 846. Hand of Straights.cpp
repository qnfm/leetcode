#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        const int n = hand.size();

        if (n % groupSize)
            return false;
        unordered_map<int, int> map;
        priority_queue<int, vector<int>, greater<int>> pq(hand.begin(), hand.end());
        for (auto v : hand)
            map[v]++;

        while (!pq.empty())
        {
            while (!pq.empty() && map[pq.top()] == 0)
                pq.pop();
            if (pq.empty())
                return true;
            int cur = pq.top();
            for (int i = 0; i < groupSize; i++)
            {
                if (map[cur + i] == 0)
                    return false;
                map[cur + i]--;
            }
        }
        return true;
    }
};