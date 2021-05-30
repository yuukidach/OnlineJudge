class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n != 1) {
            int tmp = n & 1;
            if (tmp == 1) return false;
            n >>= 1;
        }

        return true;
    }
};