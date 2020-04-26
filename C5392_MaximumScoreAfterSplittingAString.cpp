class Solution {
public:
    int maxScore(string s) {
        int len = s.size();
        int res = 0;
        int cnt[2] = {0, 0};
        for(int i = 0; i < len; ++i) {
            if (s[i] == '1') cnt[1]++;
        }
        
        for (int i = 0; i < len-1; ++i) {
            if (s[i] == '0') cnt[0]++;
            else cnt[1]--;
            res = max(res, cnt[0]+cnt[1]);
        }
        
        return res;
    }
};