class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (int i = 0; i < indices.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                mat[indices[i][0]][j]++;
            }

            for (int j = 0; j < n; ++j) mat[j][indices[i][1]]++;
        }

        int res = 0;
        for (auto row : mat) {
            for (auto cell : row) {
                if ((cell & 1) == 1) res++;
            }
        }

        return res;
    }
};