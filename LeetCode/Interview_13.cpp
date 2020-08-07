class Solution {
public:
    int movingCount(int m, int n, int k) {
        int cnt = 1;
        int dx[2] = {0, -1};
        int dy[2] = {-1, 0};
        int mark[100][100] = {0};

        mark[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int a = i, b = j;
                int sum = 0;
                while (a != 0) {
                    sum += a % 10;
                    a = a / 10;
                }
                while (b != 0) {
                    sum += b % 10;
                    b = b / 10;
                }

                if (sum <= k) {
                    for (int ii = 0; ii < 2; ++ii) {
                        int nx = i + dx[ii];
                        int ny = j + dy[ii];

                        if (nx < 0 || ny < 0) continue;
                        if (mark[nx][ny]) {
                            mark[i][j] = 1;
                            cnt++;
                            break;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};