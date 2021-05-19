class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);

        while (l <= r) {
            long sum = (long)l*l+r*r;
            if (sum > c) {
                r--;
            } else if (sum < c) {
                l++;
            } else {
                return true;
            }
        }

        return false;
    }
};