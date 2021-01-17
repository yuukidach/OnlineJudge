class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        float intercept = 0.0, pre = 0.0;
        int len = coordinates.size();
        for (int i = 0; i < len-2; ++i) {
            long a = (coordinates[i+2][0] - coordinates[i+1][0])
                     * (coordinates[i+1][1] - coordinates[i][1]);
            long b = (coordinates[i+1][0] - coordinates[i][0]) 
                     * (coordinates[i+2][1] - coordinates[i+1][1]);
            if (a != b) return false;
        }
        return true;
    }
};