class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int len = envelopes.size();
        if (!len) return len;

        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if (a[0] > b[0]) return false;
            if (a[0] < b[0]) return true;
            if (a[1] <= b[1]) return true;
            return false;
        });
        
        int *cnt = new int[len];
        for (int i = 0; i < len; ++i) {
            cnt[i] = 1;
            for (int j = i - 1; j >= 0; --j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    cnt[i] = max(cnt[i], cnt[j] + 1);
                }
            }
        } 

        return *max_element(cnt, cnt+len);
    }
};