class NumMatrix {
public:
    vector<vector<int>> mat;

    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        if (r == 0) return;
        int c = matrix[0].size();
        mat.assign(r+1, vector<int>(c+1, 0));

        for (int i = 1; i < r+1; ++i) {
            for (int j = 1; j < c+1; ++j) {
                mat[i][j] = mat[i][j-1] + matrix[i-1][j-1];
            }
        }

        for (int j = 1; j < c+1; ++j) {
            for (int i = 2; i < r+1; ++i) mat[i][j] += mat[i-1][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (mat.size() == 0) return NULL;
        return mat[row2+1][col2+1] - mat[row2+1][col1] - mat[row1][col2+1] + mat[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */