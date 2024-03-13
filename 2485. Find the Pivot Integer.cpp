class Solution
{
public:
    int pivotInteger(int n)
    {
        int root = (n * n + n) >> 1;
        long long start = 1, end = root, mid;
        while (start <= end)
        {
            mid = (start + end) >> 1;
            auto sq = mid * mid;
            if (sq == root)
                return mid;
            else if (sq < root)
            {
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        return -1;
    }
};