class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();

        int ans = 0;        

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if(grid[i][j] == 0) continue;
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        ans++;
                        continue;
                    }
                    if (grid[nx][ny] == 0) ans++;
                }
            }
        }

        return ans;
    }
};