class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());

        int pre = -1, total = 0, cnt = 0;
        for (auto &ans : answers) {
            if (total && ans == pre) {
                total--;
                continue;
            }
            pre = ans;
            cnt += 1 + ans;
            total = ans;
        }

        return cnt;
    }
};