class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int flip = 0;
        int n = A.size();
        vector<int> flag(n+1, 0);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            flip ^= flag[i];
            if (flip ^ A[i] == 0) {
                if (i + K > n) return -1;
                cnt++;
                flip ^= 1;
                flag[i + K] ^= 1;
            }
        }

        return cnt;
    }
};