#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string S)
    {
        int s = 0, f = S.size() - 1;
        while (s < f)
        {
            while (!isalnum(S[s]) && s < f)
            {
                s++;
            }
            while (!isalnum(S[f]) && s < f)
            {
                f--;
            }
            if (tolower(S[s]) != tolower(S[f]))
                return false;
            s++;
            f--;
        }
        return true;
    }
};