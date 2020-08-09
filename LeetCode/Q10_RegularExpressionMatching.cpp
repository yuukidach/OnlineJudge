class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();

        vector<vector<bool>> dp(lenp+1, vector<bool>(lens+1, false));
        dp[0][0] = true;

        for (int i = 1; i <= lenp; ++i) {
            for (int j = 0; j <= lens; ++j) {
                if (p[i-1] == '*') {
                    dp[i][j] = dp[i][j] || dp[i-2][j];
                    if ((j > 0) && (p[i-2] == s[j-1] || p[i-2] == '.'))
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                } else if ((j > 0) && (p[i-1] == s[j-1] || p[i-1] == '.')) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-1];
                }
            }
        }

        return dp[lenp][lens];
    }
};