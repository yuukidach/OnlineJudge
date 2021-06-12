class Solution {

string compStr(const string& s1, const string& s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2) return s1;
    if (len2 > len1) return s2;
    return s1 > s2 ? s1 : s2;
}

public:
    string largestNumber(vector<int>& cost, int target) {
        int len = cost.size();
        vector<string> dp(target+1, "#");
        dp[0] = "";
        
        for (int i = 1; i <= len; ++i) {
            for (int j = cost[i-1]; j <= target; ++j) {
                if (dp[j-cost[i-1]] != "#") {
                    dp[j] = compStr(dp[j], to_string(i)+dp[j-cost[i-1]]);
                }
            }
        }

        return dp[target] == "#" ? "0" : dp[target];
    }
};