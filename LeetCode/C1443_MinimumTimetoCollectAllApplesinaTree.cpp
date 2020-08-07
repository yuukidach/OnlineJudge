class Solution {
public:
    int dfs(map<int, vector<int>> &m, vector<bool>& hasApple, int idx) {
        vector<int> cnt;
        int res = 0;
        
        
        // if has aple
        if (hasApple[idx]) res = 2;

        if (m.count(idx) == 0) {
            return res;
        }
        
        // check if child node has apple
        int flag = 0;
        for (int i = 0; i < m[idx].size(); ++i) {
            cnt.push_back(dfs(m, hasApple, m[idx][i]));
            if (cnt[i]) {
                res += cnt[i];
                flag = 1;
            }
        }
        
        if (flag && !hasApple[idx]) res += 2;
        
        
        return res;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int cnt = 0;
        queue<int> q;
        map<int, vector<int>> m;
        
        for (int i = 0; i < edges.size(); ++i) {
            m[edges[i][0]].push_back(edges[i][1]);
        }
        
        for (int i = 0; i < m[0].size(); ++i) {
            cnt += dfs(m, hasApple, m[0][i]);
        }
        
        return cnt;
    }
};