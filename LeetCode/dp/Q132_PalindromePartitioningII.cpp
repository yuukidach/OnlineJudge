class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> check(n, vector<int>(n));

        // create palindrome table
        for (int i = n-1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i + 1 >= j)
                    check[i][j] = (s[i] == s[j]);
                else 
                    check[i][j] = (s[i] == s[j] && check[i+1][j-1]);
            }
        }

        int *dp = new int[n];
        for (int i = 0; i < n; ++i) dp[i] = 2001;
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (check[j][i]) {
                    if (j == 0) dp[i] = min(dp[i], 0);
                    else dp[i] = min(dp[j-1] + 1, dp[i]);
                }
            }
        }

        return dp[n-1];
    }
};