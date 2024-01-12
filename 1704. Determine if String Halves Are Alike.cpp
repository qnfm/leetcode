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

        for (int i = 0; i < n; i++)
        {
            if (i < mid && vowels.contains(s[i]))
                freq++;
            else if (i >= mid && vowels.contains(s[i]))
                freq--;
        }
        return freq == 0;
    }
};