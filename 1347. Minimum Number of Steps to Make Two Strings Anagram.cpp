#include <array>
#include <string>
using namespace std;
class Solution
{
public:
    int minSteps(string s, string t)
    {
        array<int, 26> freq{};
        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        int fs = 0, ft = 0;
        for (auto n : freq)
        {
            fs += n > 0 ? n : 0;
            ft += n < 0 ? n : 0;
        }
        // int diff = abs(s + t), r =
        return abs(fs + ft) + min(abs(ft), abs(fs));
    }
};