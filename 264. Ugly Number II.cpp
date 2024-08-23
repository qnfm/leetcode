#include <array>
#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int nthUglyNumber(int n)
    {
        array<int, 3> prime {2, 3, 5};
        priority_queue<long, vector<long>, greater<long>> minheap;
        unordered_set<long> seen;
        minheap.push(1);
        seen.insert(1);
        long cur = 1;
        for (int i = 0; i < n; i++) {
            cur = minheap.top();
            minheap.pop();
            for (auto p : prime) {
                long prod = p * cur;
                if (!seen.contains(prod)) {
                    seen.insert(prod);
                    minheap.push(prod);
                }
            }
        }
        return static_cast<int>(cur);
    }
};
