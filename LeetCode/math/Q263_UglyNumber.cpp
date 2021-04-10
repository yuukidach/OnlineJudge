class Solution {
public:
    bool isUgly(int n) {
        int left;

        if (n <= 0) return false;
        
        while (n != 1) {
            left = n % 2;
            if (left != 0) break;
            n >>= 1;
        }

        while (n != 1) {
            left = n % 3;
            if (left != 0) break;
            n /= 3;
        }

        while (n != 1) {
            left = n % 5;
            if (left != 0) return false;
            n /= 5;
        }

        return true;
    }
};