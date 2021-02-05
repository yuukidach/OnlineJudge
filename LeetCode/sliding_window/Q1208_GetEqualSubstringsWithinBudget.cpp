class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int *arr = new int[len];
        for (int i = 0; i < len; ++i) {
            arr[i] = abs(s[i]-t[i]);
        }

        int l = 0, r = 0;
        int cnt = 0, res = 0;
        while(r < len) {
            cnt += arr[r];
            if (cnt > maxCost) {
                cnt -= arr[l];
                l++;
            } else {
                res = max(res, r - l + 1);
            }
            r++;
        }

        return res;
    }
};