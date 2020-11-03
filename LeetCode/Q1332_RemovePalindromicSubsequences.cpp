class Solution {
public:
    int removePalindromeSub(string s) {
        int len = s.size();
        string sub = s;
        int cnt = 0, flag = 0;

        if (len == 0) return cnt;
        for (int i = 0; i < len / 2; ++i) {
            if (s[i] != s[len-1-i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) return 2;
        else return 1;
    }
};