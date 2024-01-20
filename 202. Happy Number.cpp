#include <string>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        int s = n, f = next(n);
        while (s != f && f != 1)
        {
            s = next(s);
            f = next(next(f));
        }
        if (f == 1)
            return true;
        return false;
    }

private:
    int next(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int rem = n % 10;
            n /= 10;
            sum += pow(rem, 2);
        }
        return sum;
    }
};