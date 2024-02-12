#include <vector>
using namespace std;
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr, const int k, int threshold)
    {
        int start = 0, end = 0, sum = 0, r = 0;
        while (end < arr.size())
        {
            sum += arr[end];
            if (end - start + 1 == k)
            {
                if (sum / k >= threshold)
                    ++r;
                sum -= arr[start];
                start++;
            }
            end++;
        }
        return r;
    }
};