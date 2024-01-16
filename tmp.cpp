/*
https://leetcode.com/problems/3sum-with-multiplicity/solutions/1918457/c-simplest-solution-w-easy-explanation-intuitive/
*/
#include <algorithm>
#include <vector>

class Solution
{
public:
    int threeSumMulti(std::vector<int> &arr, int target)
    {
        std::sort(arr.begin(), arr.end());
        long long r = 0;
        for (int k = 2; k < arr.size(); k++)
        {
            int i = 0, j = k - 1, mid, t = target - arr[k];
            while (i <= j)
            {
                mid = (i + j) / 2;
                if (t == arr[mid])
                {
                }
                else if (t < arr[mid])
                    j = mid - 1;
                else
                    i = mid + 1;
            }
        }
        return r % (1000000007);
    }
};

/*
https://www.1point3acres.com/bbs/thread-1006029-1-1.html
*/

// #include <iostream>
#include <bitset>

int main()
{
    const std::string s = "0010111100011100011";
    unsigned long long value = std::bitset<64>(s).to_ullong();
    std::cout << value << std::endl;
}

// or std::stoull

#include <iostream>
#include <string>

int main()
{
    const std::string s = "0010111100011100011";
    unsigned long long value = std::stoull(s, 0, 2);
    std::cout << value << std::endl;
}
