class Solution {
public:
    int dfs(vector<vector<int>> &richer, vector<int> &quiet, int person, vector<int> &ans) {
        if (ans[person] != -1) return ans[person];

        ans[person] = person;

        for (int i = 0; i < richer.size(); ++i) {
            if (richer[i][1] == person) {
                int s = dfs(richer, quiet, richer[i][0], ans);
                if (quiet[ans[person]] > quiet[s]) {
                    ans[person] = s;
                }
            }
        }

        return ans[person];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int len = quiet.size();
        vector<int> ans(len, -1);

        for(int i = 0; i < len; ++i) {
            dfs(richer, quiet, i, ans);
        }

        return ans;
    }
};