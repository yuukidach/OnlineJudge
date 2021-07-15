class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int res = n;
        int idx = 1;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < (i+idx)) {
                res--;
                idx--;
            }
        }

        return res;
    }
};