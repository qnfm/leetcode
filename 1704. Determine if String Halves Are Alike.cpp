#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size(), mid = n / 2, freq = 0;
        for (int i = 0; i < mid; i++)
            if (vowels.contains(s[i]))
                freq++;
        for (int i = mid; i < n; i++)
            if (vowels.contains(s[i]))
                freq--;
        return freq == 0;
    }
};