class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        if (len == 0) return true;

        int low = 0, high = 0;

        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                ++low;
                ++high;
            } else if (s[i] == ')') {
                --high;
                --low;
                if (high < 0) return false;
                if (low < 0) low = 0;
            } else {
                ++high;
                low = low > 0 ? low-1 : 0;
            }
        }

        if (low != 0) return false;
        return true;
    }
};