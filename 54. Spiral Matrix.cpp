#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> r;
        int m = matrix.size(), n = matrix[0].size(), left = 0, top = 0, right = n - 1, bottom = m - 1;
        while (left <= right && top <= bottom)
        {
            for (int j = left; j <= right; j++)
                r.push_back(matrix[top][j]);
            top++;
            for (int i = top; i <= bottom; i++)
                r.push_back(matrix[i][right]);
            right--;
            if (top <= bottom)
                for (int j = right; j >= left; j--)
                    r.push_back(matrix[bottom][j]);
            bottom--;
            if (left <= right)
                for (int i = bottom; i >= top; i--)
                    r.push_back(matrix[i][left]);
            left++;
        }
        return r;
    }
};