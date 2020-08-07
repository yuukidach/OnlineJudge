class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(!len) return "";

        int cnt = 1;
        string ss = "";
        string res;
        res += s[0];

        for (int i = 0; i < len; ++i) {
            ss += " ";
            ss += s[i];
        }
        ss += " ";

        for (int i = 1; i < ss.size(); ++i) {
            int l = 1;
            while (i - l >= 0 && i + l < ss.size() && ss[i-l] == ss[i+l]) {
                if (l > cnt) {
                    cnt = l;
                    res = ss.substr(i-l, l*2+1);
                }
                l++;
            }
        }

        string tmp;
        for (char c : res) {
            if (c != ' ') tmp += c;
        }
        return tmp;
    }
};
