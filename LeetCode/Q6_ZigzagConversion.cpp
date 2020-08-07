class Solution {
public:
    string convert(string s, int numRows) {
        string res[1000];
        int len = s.size();

        if (numRows == 1) return s;

        int line = 0;
        int dir = 1;
        for (int i = 0; i < len; ++i) {
            if (line == 0) {
                dir = 1;
            } else if (line == numRows - 1) {
                dir = -1;
            }

            res[line] += s[i];
            line += dir;
        }

        string ans;
        for (int i = 0; i < numRows; ++i) {
            ans += res[i];
        }

        return ans;
    }
};