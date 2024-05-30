#include <vector>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        vector<int> prefix(arr.size());
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum ^= arr[i];
            prefix[i] = sum;
        }
        int r = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = i; j < arr.size(); ++j)
            {
                if ((arr[i] ^ prefix[i] ^ prefix[j]) == 0)
                    r += j - i;
            }
        }
        return r;
    }
};