#include <vector>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int lo = 0, hi = matrix.size() - 1, mid;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            if (target == matrix[mid][0])
                return true;
            else if (target < matrix[mid][0])
            {
                hi = mid - 1;
            }
            else
            {
                if (target <= matrix[mid][matrix[0].size() - 1])
                    return bs(matrix[mid], target);
                lo = mid + 1;
            }
        }
        return false;
    }

private:
    bool bs(vector<int> &row, int target)
    {
        int lo = 0, hi = row.size() - 1, mid;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            if (target == row[mid])
                return true;
            else if (target < row[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};