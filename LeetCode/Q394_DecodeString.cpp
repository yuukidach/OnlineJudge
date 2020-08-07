class Solution {
public:
    int find_bracket(string s, int l) {
        int cnt = 1;
        for (int i = l+1; i < s.size(); ++i) {
            if (s[i] == '[') cnt++;
            else if (s[i] == ']') cnt--;
            if (cnt == 0) return i;
        }

        return -1;
    }

    string decodeString(string s) {
        string res;

        int cnt = 0;
        for (int i = 0; i < s.size();) {
            char ch = s[i];
            if (ch >= '0' && ch <= '9') {
                cnt = cnt * 10 + ch - '0';
                i++;
            }
            else if (ch == '[') {
                int r = find_bracket(s, i);
                for(int j = 0; j < cnt; ++j) {
                    res += decodeString(s.substr(i+1, r-i-1));
                }
                cnt = 0;
                i = r + 1;
            }
            else {
                res += ch;
                cnt = 0;
                i++;
            }
        }

        return res;
    }
};
