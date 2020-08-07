class Solution {
public:
    int translateNum(int num) {
        vector<int> nbit;
        if (num == 0) return 1;
        
        while(num != 0) {
            nbit.insert(nbit.begin(), num % 10);
            num /= 10;
        }

        int len = nbit.size();
        int dp[len+1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= len; ++i) {
            dp[i] = dp[i-1];
            int tmp = nbit[i-1] + 10 * nbit[i-2];
            if (tmp > 9 && tmp < 26) dp[i] += dp[i-2];
        }

        return dp[len];
    }
};