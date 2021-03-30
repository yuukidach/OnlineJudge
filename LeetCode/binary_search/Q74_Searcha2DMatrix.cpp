class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0, r = m;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) l = mid + 1;
            else r = mid;
        }

        if (l >= m || matrix[l][0] > target) l--;
        if (l < 0) return false;
        m = l;
        l = 0;
        r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[m][mid] == target) return true;
            else if (matrix[m][mid] < target) l = mid + 1;
            else r = mid;
        }

        return false;
    }
};