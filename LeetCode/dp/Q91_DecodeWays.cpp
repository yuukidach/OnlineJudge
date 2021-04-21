class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len+5, 0);

        dp[0] = 1;

        for (int i = 0; i < len; ++i) {
            int num1 = s[i] - '0';
            int num2 = 0;
            if (i > 0) num2 = (s[i-1] - '0') * 10 + num1;

            if (num1 > 0 && num1 < 10) dp[i+1] = dp[i];
            if (num2 > 9 && num2 < 27) dp[i+1] += dp[i-1];    
        }

        return dp[len];
    }
};