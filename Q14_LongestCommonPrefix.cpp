class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int minlen = INT_MIN;
        if (strs.size() == 0) return "";

        for (string str : strs) {
            minlen = minlen < str.size() ? minlen : str.size();
        }

        int anslen;

        for (anslen = 0; anslen < minlen; anslen++) {
            char c = strs[0][anslen];
            int flag = 0;
            for (string str : strs) {
                if (str[anslen] != c) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }

        for (int i = 0; i < anslen; ++i) ans += strs[0][i]; 

        return ans;
    }
};