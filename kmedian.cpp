#include <algorithm>
#include <vector>
using namespace std;
int minmove(vector<int>& arr, int k)
{
    if (arr.size() == 1)
        return abs(k - arr[0]);
    sort(arr.begin(), arr.end());
    int small = 0, large = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < k)
            ++small;
        else {
            large = arr.size() - small;
            break;
        }
    }
    const int sz = arr.size(), idx = sz / 2;
    int r = 0;
    if (sz & 1) {
        if (large == small)
            return abs(k - arr[idx]);
        if (large > small) {
            // small -- idx
            for (int i = small; i <= idx; i++)
                r += abs(k - arr[i]);
            return r;
        }
        // idx -- small - 1
        for (int i = idx; i < small; i++)
            r += abs(k - arr[i]);
        return r;
    } else {
        if (large == small)
            return abs(k - arr[idx - 1]) + abs(k - arr[idx]);
        if (large > small) {
            // small -- idx
            for (int i = small; i <= idx; i++)
                r += abs(k - arr[i]);
            return r;
        }
        // idx - 1 -- msall -1
        for (int i = idx - 1; i < small; i++)
            r += abs(abs(k - arr[i]));
        return r;
    }
}
