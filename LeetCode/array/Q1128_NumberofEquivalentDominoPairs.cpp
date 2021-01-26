class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int len = dominoes.size();
        vector<vector<int>> mat(10, vector<int>(10, 0));
        for (int i = 0; i < len; ++i) {
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            if (a>b) swap(a, b);
            mat[a][b]++;
        }

        int cnt = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = i; j < 10; ++j) {
                if (mat[i][j] > 1) cnt += mat[i][j] * (mat[i][j] - 1) >> 1;
            }
        }
        return cnt;
    }
};