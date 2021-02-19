class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        int l = 0, r = 0;

        int cnt = K, res = 0;
        while (r < n) {
            while (r < n && A[l] == 0) {
                l++;
                r=l;
                cnt = K;
            }
            if (r >= n) break;
            if (A[r] == 1) r++;
            else if (A[r] == 0 && cnt) {
                r++;
                cnt--;
            } else {
                res = max(res, r - l);
                while(A[l] == 1) l++;
            }
        }

        res = max(res, r - l + cnt);
        res = min(res, n);
        return res;
    }
};