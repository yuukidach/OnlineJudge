class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, vector<int>> m;

        for (auto &piece : pieces) {
            m[piece[0]] = piece;
        }

        for (int i = 0; i < arr.size();) {
            int num = arr[i];
            if (m.count(num) == 0) return false;
            for (int j = 0; j < m[num].size(); ++j, ++i) {
                if (m[num][j] != arr[i]) return false;
            }
        }

        return true;
    }
};