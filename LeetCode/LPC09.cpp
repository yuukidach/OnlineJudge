class Solution {
public:
    int minJump(vector<int>& jump) {
        int len = jump.size();
        int *dp = new int[len];
        int res = 0;

        memset(dp, 111111, sizeof(int)*len);
        dp[0] = 0;
        
        queue<int> s;
        s.push(0);
        
        int start = 0;
        while(!s.empty()) {
            int idx = s.front();
            s.pop();
            
            if (idx + jump[idx] >= len) {
                res = dp[idx] + 1;
                return res;
            }
            
            for (int i = start; i < idx; ++i) {
                if (dp[i] > dp[idx] + 1) {
                    dp[i] = dp[idx] + 1;
                    s.push(i);
                }        
            }
            
            if (dp[idx+jump[idx]] > dp[idx] + 1) {
                dp[idx+jump[idx]] = dp[idx] + 1;
                s.push(idx+jump[idx]);
            }

            start = idx;
            
        }
        return res;
    }
};