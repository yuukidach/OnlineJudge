class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int len = people.size();

        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<vector<int>> res(len);

        for (auto person : people) {
            int space = person[1] + 1;
            for (int i = 0; i < len; ++i) {
                if (res[i].empty()) {
                    space--;
                }
                if (space == 0) {
                    res[i] = person;
                    break;
                }
            }
        }

        return res;
    }
};