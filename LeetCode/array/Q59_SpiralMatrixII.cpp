class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));

        int left = 0, right = n-1, up = 0, down = n-1;
        int cnt = 1, bound = n*n;
        while (true) {
            for (int i = left; i <= right; ++i) res[up][i] = cnt++;
            up++;
            if (cnt > bound) break;
            for (int i = up; i <= down; ++i) res[i][right] = cnt++;
            right--;
            if (cnt > bound) break;
            for (int i = right; i >= left; --i) res[down][i] = cnt++;
            down--;
            if (cnt > bound) break;
            for (int i = down; i >= up; --i) res[i][left] = cnt++;
            left++;
            if (cnt > bound) break;
        }

        return res;
    }
};