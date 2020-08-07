class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int len = points.size();
    
        if (len == 0) return 0;
        
        sort(points.begin(), points.end(), 
             [](const vector<int> a, const vector<int> b) {
                 return a[0] < b[0];
             });
        int l = points[0][1];
        int nl = l;
        int cnt = 1;

        for (int i = 1; i < len; ++i) {
            if (points[i][1] <= l) {
                l = points[i][1];
                continue;
            }
            if (points[i][0] <= l) continue;

            l = points[i][1];
            cnt++;
        }
        
        return cnt;
    }
};