class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if (!len) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        
        int res = 0;

        int i = 0, j = 1;
        while (j < len) {
            vector<int> pre = intervals[i];
            vector<int> cur = intervals[j];
            if (pre[1] <= cur [0]) {
                i = j;
                j++;
                continue;
            }

            res++;

            if (pre[1] >= cur[1]) {
                i = j;
                j++;
            } else {
                j++;
            }
        }

        return res;
    }
};