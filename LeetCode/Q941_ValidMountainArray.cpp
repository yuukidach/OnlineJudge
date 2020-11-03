class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int len = A.size();
        if (len == 0) return false;

        int last = INT_MIN;
        int idx = INT_MIN;

        for (int i = 0; i < len; ++i) {
            if (A[i] <= last) break;
            last = A[i];
            idx = i;
        }

        if (idx <= 0 || idx >= len-1) return false;
        for (int i = idx + 1; i < len; ++i) {
            if (A[i] >= last) return false;
            last = A[i];
        }

        return true;
    }
};