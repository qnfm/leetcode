#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k)
    {
        vector<int> fac;
        for (int i = 1; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                fac.push_back(i);
                if (i * i != n)
                    fac.push_back(n / i);
            }
        }
        sort(fac.begin(), fac.end());
        if (fac.size() < k)
            return -1;
        return fac[k - 1];
    }
};