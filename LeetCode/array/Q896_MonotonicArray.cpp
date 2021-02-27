class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int len = A.size(), flag;
        if (len <= 2) return true;
        int i;
        for (i = 1; i < len; ++i) {
            if (A[i] > A[i-1]) {
                flag = 1;
                break;
            } else if (A[i] < A[i-1]) {
                flag = -1;
                break;
            }
        }

        for (; i < len; ++i) {
            if ((A[i] - A[i-1]) * flag < 0) return false;
        }
        
        return true;
    }
};