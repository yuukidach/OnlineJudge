class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        int cnt = 0;
        int l =0, r =0, last_l = 0, last_r = 0;

        int next[len+1];
        memset(next, -1, sizeof(int) * (len + 1));
        for (int i = 0; i < len; ++i) {
            if ((nums[i] & 1) == 0) continue;
            next[l] = i + 1;
            l = i + 1;
        }

        l = 0;
        for (int i = 0; i < k; ++i) {
            if (next[r] == -1) return 0;
            r = next[r];
        }

        while(next[r] != -1) {
            last_r = r;
            r = next[r];
            last_l = l;
            l = next[l];

            cnt += (l - last_l) * (r - last_r);
        }

        last_r = r;
        r = len + 1;
        last_l = l;
        l = next[l];
        cnt += (l - last_l) * (r - last_r);

        return cnt;
    }
};