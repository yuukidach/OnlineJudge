class Solution {
public:
    int cntDigits(int n) {
        int res = 0;
        while (n != 0) {
            int a = n % 10;
            res += a * a;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int a = n, b = n;
        b = cntDigits(n);
        while (a != b && a != 1 && b != 1){
            a = cntDigits(a);
            b = cntDigits(b);
            b = cntDigits(b);
        }

        return (a == 1 || b == 1);    
    }
};