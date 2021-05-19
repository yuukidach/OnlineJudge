class Solution {
public:
    bool canCross(vector<int>& stones) {
        bool dp[2005][2005] = {false};

        dp[0][0] = true;
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = i-1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > i) break;
                dp[i][k] |= (dp[j][k-1] || dp[j][k+1] || dp[j][k]);
            }
        }
        
        for(int i = 0; i < stones.size(); ++i) {
            if (dp[stones.size()-1][i]) return true;
        }
        
        return false;
    }
};