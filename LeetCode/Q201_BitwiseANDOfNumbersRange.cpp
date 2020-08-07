class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = n;
        for (int i = m; i < n; ++i) {
            res &= i;
            if (res == 0) break;
        }

        return res;
    }
};