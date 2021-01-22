class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n == 0) return false;
        int m = matrix[0].size();
        if (m == 0) return false;

        int i = 0, j = m-1;
        while (i < n && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] > target) {
                j--;
                continue;
            }
            if (matrix[i][j] < target) {
                i++;
                continue;
            }
        }

        return false;
    }
};