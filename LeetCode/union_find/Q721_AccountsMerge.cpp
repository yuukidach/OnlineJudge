class Solution {
public:
    int findPre(vector<int> &pre, int i) {
        while (i != pre[i]) {
            pre[i] = pre[pre[i]];
            i = pre[i];
        }
        return i;
    }

    void Union(vector<int> &pre, int i, int j) {
        int r1 = findPre(pre, i);
        int r2 = findPre(pre, j);
        pre[r1] = pre[r2]; 
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> pre(n);
        unordered_map<string, int> mail2name;

        for(int i = 0; i < n; ++i) {
            pre[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                string mail = accounts[i][j];
                if (mail2name.count(mail) != 0) Union(pre, i, mail2name[mail]);
                else mail2name[mail] = findPre(pre, i);
            }
        }

        vector<vector<string>> res(n);
        for (auto const &[key, val] : mail2name) {
            int root = findPre(pre, val);
            if (res[root].empty()) res[root].push_back(accounts[root][0]);
            res[root].push_back(key);
        }

        for (int i = 0; i < res.size();) {
            if (res[i].size() == 0) res.erase(res.begin() + i);
            else ++i;
        }

        for (int i = 0; i < res.size(); ++i) {
            sort(res[i].begin()+1, res[i].end());
        }
        return res;
    }
};