class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        char pre = ' ', cur;
        vector<vector<int>> res;
        int cnt = 0, start = -1;
        int len = s.size();

        for (int i = 0; i < len; ++i) {
            cur = s[i];
            if (cur == pre) {
                cnt++;
            } else {
                if (cnt >= 3) {
                    vector<int> cell{start, i-1};
                    res.emplace_back(cell);
                }
                cnt = 1;
                start = i;
            }
            pre = cur;
        }

        if (cnt >= 3) {
            vector<int> cell{start, len-1};
            res.emplace_back(cell);
        }
        
        return res;
    }
};