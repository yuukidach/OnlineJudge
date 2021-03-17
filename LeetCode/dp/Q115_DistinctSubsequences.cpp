#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 =s.size(), len2 = t.size();
        if (len1 < len2) return 0;
        if (len1 == 0 || len2 == 0) return 0;

        vector<vector<long>> dp(len1, vector<long>(len2));
        dp[0][0] = (s[0] == t[0]);

        for (int i = 1; i < len1; ++i) {
            dp[i][0] = dp[i-1][0] + (s[i] == t[0]);
            for (int j = 1; j < len2 && j <= i; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[len1-1][len2-1];
    }
};


int main() {
    Solution solution;
    cout << solution.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}