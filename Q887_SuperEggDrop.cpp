class Solution {
public:
    int superEggDrop(int K, int N) {
        int mark[K+1][N+1];

        if (K == 1) return N;
        int res = 111111;
        memset(mark, 111111, sizeof(int) * (K+1) * (N+1));

        for (int i = 1; i <= N; ++i) {
            mark[1][i] = i;
        }
        for (int i = 1; i <= K; ++i) {
            mark[i][1] = 1;
            mark[i][0] = 0;
        }

        for (int i = 2; i <= K; ++i) {
            int m = 1;
            for (int j = 2; j <= N; ++j) {
                while (m < j && mark[i-1][m-1] <= mark[i][j-m]) m++;
                int max_dp = min(mark[i][j-m+1], mark[i-1][m-1]);
                mark[i][j] = min(max_dp + 1, mark[i][j]);
            }
        }

        return mark[K][N];
    }
};