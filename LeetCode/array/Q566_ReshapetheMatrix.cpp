class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int a = nums.size();
        int b = nums[0].size();

        if (a*b != r*c) return nums;

        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                res[(i*b+j)/c][(i*b+j)%c] = nums[i][j];
            }
        }

        return res;
    }
};