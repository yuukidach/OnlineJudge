class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            mat[i][0] = matrix[i][0];
            for (int j = 1; j < n; ++j) {
                mat[i][j] = mat[i][j-1] ^ matrix[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                mat[j][i] ^= mat[j-1][i];
            }
        }

        priority_queue<int> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                pq.push(mat[i][j]);
            }
        }

        while (k > 1) {
            pq.pop();
            k--;
        }

        return pq.top();
    }
};