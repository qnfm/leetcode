#include <algorithm>
#include <array>
#include <string>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if (word1.size() != word2.size())
            return false;
        array<int, 26> f1{}, f2{};
        for (int i = 0; i < word1.size(); i++)
        {
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if ((!f1[i] && f2[i]) || (f1[i] && !f2[i]))
                return false;
        }
        sort(f1.begin(), f1.end(), greater<int>());
        sort(f2.begin(), f2.end(), greater<int>());
        for (int i = 0; i < 26; i++)
        {
            if (f1[i] == f2[i] && f1[i] == 0)
                return true;
            if (f1[i] != f2[i])
                return false;
        }
        return true;
    }
};