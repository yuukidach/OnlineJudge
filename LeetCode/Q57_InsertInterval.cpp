class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return (a[0] < b[0]);
        });

        int len = intervals.size();
        if (len == 1) return intervals;
        vector<vector<int>> res;

        for (int i = 0; i < len-1; ++i) {
            if (intervals[i][1] < intervals[i+1][0]) {
                res.emplace_back(intervals[i]);
            } else {
                intervals[i+1][0] = intervals[i][0];
                intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
            }
        }

        res.emplace_back(intervals[len-1]);

        return res;
    }
};