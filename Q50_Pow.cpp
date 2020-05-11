class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0) return 1;
        if (n < 0) return 1/myPow(x, -n);
        double res = myPow(x, n >> 1);
        if (n & 1) res = res * res * x;
        else res = res * res;

        return res;
    }
};