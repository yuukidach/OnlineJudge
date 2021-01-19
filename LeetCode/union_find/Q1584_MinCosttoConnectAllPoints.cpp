class Solution {
public:
    struct edge {
        int len, x, y;
        edge(int len, int x, int y): len(len), x(x), y(y) {
        }
    };

    int cntDist(vector<vector<int>> &points, int i, int j) {
        return (abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
    }

    int find(vector<int> &pre, int i) {
        while (i != pre[i]) {
            pre[i] = pre[pre[i]];
            i = pre[i];
        }
        return i;
    }

    void Union(vector<int> &pre, int i, int j) {
        int ri = find(pre, i);
        int rj = find(pre, j);
        pre[ri] = rj;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<edge> edges;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                edges.emplace_back(cntDist(points, i, j), i, j);
            }
        }

        sort(edges.begin(), edges.end(), [](edge a, edge b){
            return a.len < b.len;
        });

        int cnt = 1, total = 0;
        vector<int> pre(n);
        for (int i = 0; i < n; ++i) pre[i] = i;

        for (auto &[len, x, y] : edges) {
            if (find(pre, x) == find(pre, y)) continue;
            total += len;
            Union(pre, x, y);
            if (cnt++ == n) break;
        }

        return total;
    }
};