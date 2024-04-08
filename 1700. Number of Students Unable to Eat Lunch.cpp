#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int countStudents(vector<int> &st, vector<int> &sd)
    {
        deque<bool> dq;
        int i = 0;
        int unable = 0;
        for (auto pre : st)
            dq.push_back(pre);

        int lastServed = 0;
        while (!dq.empty() && i < sd.size() && lastServed < dq.size())
        {
            if (dq.front() == sd[i])
            {
                lastServed = 0;
                dq.pop_front();
                ++i;
            }
            else
            {
                dq.push_back(dq.front());
                dq.pop_front();
                ++lastServed;
            }
        }
        return dq.size();
    }
};