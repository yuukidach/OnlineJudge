class Solution {
public:
    int backtrack(int *arr, int idx, int pos, int n) {
        if ((idx+1) % (pos) != 0 && (pos) % (idx+1) != 0) return 0;
        if (pos >= n) return 1;
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == 1) continue;
            arr[i] = 1;
            cnt += backtrack(arr, i, pos+1, n);
            arr[i] = 0;
        }
        return cnt;
    }

    int countArrangement(int n) {
        int *arr = new int[n];
        memset(arr, 0, n*sizeof(int));
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            arr[i] = 1;
            cnt += backtrack(arr, i, 1, n);
            arr[i] = 0;
        }
        return cnt;
    }
};