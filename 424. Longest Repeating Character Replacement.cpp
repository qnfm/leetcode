#include <string>
#include <array>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        array<int, 26> freq{};
        int start = 0, end = 0, maxfreq = 0;
        int r = 0;
        while (end < s.size())
        {
            freq[s[end] - 'A']++;
            maxfreq = max(maxfreq, freq[s[end] - 'A']);
            if (end - start + 1 - maxfreq > k)
            {
                freq[s[start] - 'A']--;
                start++;
            }
            r = max(r, end - start + 1);
            end++;
        }
        return r;
    }
};