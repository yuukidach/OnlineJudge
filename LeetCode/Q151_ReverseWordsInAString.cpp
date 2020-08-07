class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();

        while (s.size() > 0) {
            if (s[0] != ' ') break;
            s.erase(0, 1);
        }
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] != ' ') break;
            s.erase(i, 1);
        }
        for (int i = 1; i < s.size();) {
            if (s[i] == ' ' && s[i-1] == ' ') s.erase(i, 1);
            else ++i;
        }
        len = s.size();

        for (int i = 0; i < len;) {
            int idx = i;
            while (s[idx] != ' ' && idx < len) idx++;

            for (int j = i; j < (i+idx >> 1); ++j) {
                s[j] ^= s[idx+i-j-1];
                s[idx+i-j-1] ^= s[j];
                s[j] ^= s[idx+i-j-1];
            }

            i = idx + 1;
        }

        for (int i = 0; i < (len >> 1); ++i) {
            s[i] ^= s[len-1-i];
            s[len-1-i] ^= s[i];
            s[i] ^= s[len-1-i];
        }

        return s;
    }
};