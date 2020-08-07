class Solution {
public:
    int reverse(int xx) {
        vector<int> bits;

        long long x = xx;

        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = -x;
        }
        
        long long res = 0;
        while (x != 0) {
            bits.push_back(x % 10);
            x /= 10;
        }

        for (int b : bits) {
            res = res * 10 + b;
        }

        res *= flag;

        if (res > INT_MAX || res < INT_MIN) return 0;

        return res;
    }
};