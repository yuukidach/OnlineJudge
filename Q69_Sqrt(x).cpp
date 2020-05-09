class Solution {
public:
    int mySqrt(int x) {
        int cnt = 0;
        int tmp = x;
        while (tmp != 0) {
            cnt++;
            tmp >>= 1;
        }

        for (int i = 1; i <= (1<<(cnt/2+1)); ++i) {
            long long a = (long long)i*i;
            if (a > x) return i-1;
        }

        return 1;
    }
};