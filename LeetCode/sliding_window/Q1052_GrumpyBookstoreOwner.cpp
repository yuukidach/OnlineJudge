class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int len = grumpy.size();
        int res = 0;

        for (int i = 0; i < len; ++i) {
            if (grumpy[i] == 0) res += customers[i];
            customers[i] *= grumpy[i];
        }

        int l = 0, r = 0, cnt = 0, s = 0;
        while (r < len) {
            cnt += customers[r];
            r++;
            while (r - l > X) {
                cnt -= customers[l];
                l++;
            }
            s = max(s, cnt);
        }

        return s + res;
    }
};