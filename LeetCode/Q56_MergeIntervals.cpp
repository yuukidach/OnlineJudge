class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        });

        int len = intervals.size();
        if (len == 0) return intervals;
        
        int r = intervals[0][1];
        int idx = 0;
        for (int i = 1; i < len; ++i) {
            int l = intervals[i][0];
            if (r >= l) {
                r = max(r, intervals[i][1]);
                intervals[idx][1] = r;
                intervals[i][0] = INT_MIN;
                continue;
            }

            r = intervals[i][1];
            idx = i;
        }

        vector<vector<int>> res;
        for (int i = 0; i < len; ++i) {
            if (intervals[i][0] != INT_MIN) res.push_back(intervals[i]);
        }

        return res;
    }
};