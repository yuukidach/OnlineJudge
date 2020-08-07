class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        int dp[len+1][len+1];

        for (int i = len-1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < len; ++j) {
                bool is_equal = (s[i] == s[j]);

                if (j == i+1) {
                    dp[i][j] = is_equal ? 2 : 1;
                    continue;
                }

                if (is_equal) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][len-1];
    }
};