class Solution {
public:
    int romanToInt(string s) {
        map<char, int> table = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int pre = INT_MAX;
        int res = 0;
        for (char c : s) {
            int d = table[c];
            if (d > pre) {
                res -= pre;
                res = res + d - pre;
            } else {
                res += d;
            }
            pre = d;
        }

        return res;
    }
};