#include <array>
#include <string>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        if (m > n)
            return false;
        int start = 0, end = 0;
        array<int, 26> freq{};
        int i = 0;
        while (i < m)
        {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
            i++;
        }
        if (isperm(freq))
            return true;
        for (int j = 0; i < n; i++, j++)
        {
            freq[s2[j] - 'a']++;
            freq[s2[i] - 'a']--;
            if (isperm(freq))
                return true;
        }
        return false;
    }

private:
    bool isperm(array<int, 26> &freq)
    {
        for (auto &v : freq)
            if (v != 0)
                return false;
        return true;
    }
};