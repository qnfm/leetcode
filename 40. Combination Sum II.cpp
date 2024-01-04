#include <vector>
#include <algorithm>
using namespace std;
/*
#include <vector>
#include <array>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> cur;
        array<int, 50> a{0};
        int sum = 0;
        for (int i = 0; i < ori.size(); i++) ori[i] = 0;
        for (const auto v: candidates) {
            sum += v;
            ori[v - 1]++;
        }
        if (sum >= target) comb(candidates, target, a, cur, 0);
        return r;
    }

private:
    vector<vector<int>> r;
    unordered_set<string> set;
    array<int, 50> ori;

    void comb(vector<int> &can, int target, array<int, 50> check, vector<int> curr, int idx) {
        if (target < 0) return;
        if (target == 0) {
            string tmp;
            for (int i = 0; i < check.size(); i++) {
                if (check[i] != 0) tmp += to_string(i) + ":" + to_string(check[i]) + "#";
            }
            if (!set.contains(tmp)) {
                set.insert(tmp);
                r.push_back(curr);
            }
            return;
        }
        for (int i = idx; i < can.size(); i++) {
            check[can[i] - 1]++;
            if (check[can[i] - 1] <= ori[can[i] - 1]) {
                curr.push_back(can[i]);
                comb(can, target - can[i], check, curr, idx + 1);
                curr.pop_back();
            }
            check[can[i] - 1]--;

        }
    }
};
*/
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        this->target = target;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, cur);
        return r;
    }

private:
    int target;
    vector<vector<int>> r;
    void dfs(vector<int> &can, int i, int sum, vector<int> cur)
    {
        if (sum == target)
        {
            r.push_back(cur);
            return;
        }
        if (target < sum)
            return;
        for (int j = i; j < can.size(); j++)
        {
            if (j > i && can[j] == can[j - 1])
                continue;
            cur.push_back(can[j]);
            dfs(can, j + 1, sum + can[j], cur);
            cur.pop_back();
        }
    }
};