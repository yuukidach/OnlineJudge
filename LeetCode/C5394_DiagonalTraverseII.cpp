class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int rlen = nums.size();
        vector<pair<int, int>> m;
        for (int i = 0; i < rlen; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                m.push_back(make_pair(i, j));
            }
        }

        sort(m.begin(), m.end(), [](pair<int, int>a, pair<int, int> b) {
            if (a.first + a.second < b.first + b.second) return true;
            if (a.first + a.second == b.first + b.second) return a.first > b.first;
            return false;
        });

        vector<int> res;
        for(int i = 0; i < m.size(); ++i) {
            res.push_back(nums[m[i].first][m[i].second]);
        }

        return res;
    }
};