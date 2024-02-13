#include <array>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        len = nums.size();
        array<char, 21> cnt{};
        for (auto n : nums)
        {
            cnt[n + 10]++;
        }
        vector<int> cur;
        bt(cur, cnt);
        return r;
    }

private:
    int len = 0;
    vector<vector<int>> r;
    void bt(vector<int> cur, array<char, 21> &arr)
    {
        if (cur.size() == len)
        {
            r.push_back(cur);
            return;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
            {
                arr[i]--;
                cur.push_back(i - 10);
                bt(cur, arr);
                arr[i]++;
                cur.pop_back();
            }
        }
    }
};