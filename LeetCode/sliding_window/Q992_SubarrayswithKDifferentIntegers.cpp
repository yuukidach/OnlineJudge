class Solution {
public:
    int getMaxLen(vector<int> &a, int k) {
        int l = 0, r = 0;
        vector<int> arr(a.size() + 1, 0);
        int len = 0, cnt = 0;
        while (r < a.size()) {
            if (arr[a[r]] == 0) cnt++;
            arr[a[r]]++;
            r++;

            while (cnt > k) {
                arr[a[l]]--;
                if (arr[a[l]] == 0) cnt--;
                l++;
            }

            len += r - l;
        }
        return len;
    }

    int subarraysWithKDistinct(vector<int>& A, int K) {
        return getMaxLen(A, K) - getMaxLen(A, K-1);
    }
};