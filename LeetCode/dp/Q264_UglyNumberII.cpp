class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n+1];
        dp[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;

        for (int i = 1; i < n; ++i) {
            int num = min(dp[p2] * 2, dp[p3] * 3);
            num = min(num, dp[p5] * 5);
            dp[i] = num;
            if (num == dp[p2] * 2) {
                p2++;
            }
            if (num == dp[p3] * 3) {
                p3++;
            }
            if (num == dp[p5] * 5){
                p5++;
            }
        }

        return dp[n-1];
    }
};
