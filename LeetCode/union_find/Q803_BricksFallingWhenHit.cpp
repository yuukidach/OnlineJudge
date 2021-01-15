class Solution {
public:
    int roof;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    int findParent(vector<int> &s, int i) {
        while (i != s[i]) {
            s[i] = s[s[i]];
            i = s[i];
        }
        return i;
    }

    void Union(vector<int> &s, vector<int> &size, int i, int j) {
        int r1 = findParent(s, i);
        int r2 = findParent(s, j);
        if (r1 == r2) return;
        if (r1 == roof) {
            s[r2] = r1;
            size[r1] += size[r2];
        } else {
            s[r1] = r2;
            size[r2] += size[r1];
        }
    }

    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<vector<int>> mm(grid);
        int m = grid.size();
        int n = grid[0].size();
        int len = hits.size();

        for (auto hit : hits) {
            mm[hit[0]][hit[1]] = 0;
        }

        roof = m * n;
        vector<int> s(m*n+1, -1);
        vector<int> size(m*n+1, 1);
        s[roof] = roof;
        size[roof] = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                s[i*n+j] = i*n+j;
                // size[i*n+j] = mm[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (mm[0][i] == 1) Union(s, size, i, roof);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mm[i][j] == 0) continue;
                for (int k = 0; k < 2; ++k) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if (nx < 0) continue;
                    if (mm[ny][nx] == 0) continue;
                    Union(s, size, i*n+j, ny*n+nx);
                }
            }
        }

        vector<int> res;
        for (int i = len-1; i >= 0; --i) {
            int y = hits[i][0];
            int x = hits[i][1];
            if (grid[y][x] == 0) {
                res.push_back(0);
                continue;
            }
            mm[y][x] = 1;
            
            int origin = size[roof];
            if(y == 0) Union(s, size, y*n+x, roof);
            for (int k = 0; k < 4; ++k) {
                int ny = y + dy[k], nx = x + dx[k];
                if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                if (mm[ny][nx] == 0) continue;
                Union(s, size, y*n+x, ny*n+nx);
            }
            int drop = size[roof] - origin - 1;
            res.push_back(drop > 0 ? drop : 0);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};