#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        const auto N = deck.size();
        int idxResult = 0;
        int idxDeck = 0;
        bool skip = false;
        vector<int> result(N);
        sort(deck.begin(), deck.end());
        while (idxDeck < N)
        {
            if (result[idxResult] == 0)
            {
                if (!skip)
                {
                    result[idxResult] = deck[idxDeck];
                    ++idxDeck;
                }
                skip = !skip;
            }
            idxResult = (idxResult + 1) % N;
        }
        return result;
    }
};