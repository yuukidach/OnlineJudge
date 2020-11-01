class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len+1, false);
        unordered_map<string, int> map;

        for (auto x : wordDict) {
            map.insert(pair<string, int>(x, 1));
        }

        dp[0] = true;

        for(int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (!dp[j]) continue;
                string r = s.substr(j, i-j);
                if(map.count(r)) dp[i] = true;
                if (dp[i]) break;
            }
        }

        return dp[len];
    }
};