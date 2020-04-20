class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rlen = grid.size();

        if (rlen == 0) return 0;
        
        int clen = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};

        int cnt = 0;
        for(int i = 0; i < rlen; ++i) {
            for (int j = 0; j < clen; ++j) {
                if (grid[i][j] == '0') continue;
                cnt++;
                grid[i][j] = '0';
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                while(!q.empty()) {
                    auto cor = q.front();
                    q.pop();
                    for(int k = 0; k < 4; ++k) {
                        int nx = cor.second + dx[k];
                        int ny = cor.first + dy[k];
                        if (nx < 0 || ny < 0 || nx >= clen || ny >= rlen) continue;
                        if (grid[ny][nx] != '0') {
                            grid[ny][nx] = '0';
                            q.push(make_pair(ny, nx));
                        }
                    }
                }
            }
        }

        return cnt;
    }
};