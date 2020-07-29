class Solution {
public:
    bool dfs(int n, vector<vector<int>> &g, vector<int> &mark, int color) {
        if (color != mark[n] && mark[n] != 0) return false;
        else if (color == mark[n]) return true;

        bool res = true;
        mark[n] = color;
        for (int i = 0; i < g[n].size(); ++i) {
            res &= dfs(g[n][i], g, mark, 3 - color);
        }

        return res;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> mark(len, 0);
        bool res = true;

        for (int i = 0; i < len; ++i) {
            if (mark[i] == 0) res &= dfs(i, graph, mark, 1);
            if (!res) return false;
        }

        return true;
    }
};
