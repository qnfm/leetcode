#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string slow = to_string(low), shigh = to_string(high);
        int wlow = slow.size(), whigh = shigh.size(), N = 10;
        for (int i = wlow; i <= whigh; i++)
        {
            for (int start = 0; start < N - i; start++)
            {
                int cur = stoi(all.substr(start, i));
                if (cur >= low && cur <= high)
                    r.push_back(cur);
            }
        }
        return r;
    }

private:
    string all = "123456789";
    vector<int> r;
};