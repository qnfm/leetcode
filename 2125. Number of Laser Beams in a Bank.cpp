#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int rsz = bank.size(), csz = bank[0].size(), r = 0;
        if (rsz < 2)
            return 0;
        vector<int> no;
        for (const auto &row : bank)
        {
            int sum = 0;
            for (const auto v : row)
                sum += v - '0';
            no.push_back(sum);
        }
        int i = 0, j = 0;
        while (j < rsz)
        {
            if (no[j])
            {
                if (i < j && no[i])
                    r += no[i++] * no[j++];
                else if (i == j)
                    j++;
                else
                    i++;
            }
            else
                j++;
        }
        return r;
    }
};