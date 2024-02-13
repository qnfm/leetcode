#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        unordered_map<char, int> cnt;
        int len = 0;
        int l = 0, r = 0;
        while (r < answerKey.size())
        {
            cnt[answerKey[r]]++;
            while (cnt['T'] > k & cnt['F'] > k)
            {
                cnt[answerKey[l++]]--;
            }
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};