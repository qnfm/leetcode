class Solution
{
public:
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        int cur = 0, prev = 1, np = 0;
        for (int i = 2; i <= n; i++)
        {
            cur = prev + np;
            np = prev;
            prev = cur;
        }
        return cur;
    }
};