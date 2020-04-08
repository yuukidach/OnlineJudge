class Solution {
public:
    int longestPalindrome(string s) {
        int len = s.size();
        int mark[128] = {0};
        int ans = 0;
        int odd_len = 0;

        for (int i = 0; i < len; ++i) mark[s[i]]++;
        for (int i = 'A'; i <= 'z'; ++i) ans += mark[i] - (mark[i] & 1);
        ans = ans < len? ans + 1 : ans;

        return ans;
    }
};