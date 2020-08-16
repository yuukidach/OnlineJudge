class Solution {
public:
    const int dr[4] = {1, 0, -1, 0};
    const int dc[4] = {0, -1, 0, 1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        int rlen = image.size();
        if (rlen == 0) return image;
        int clen = image[0].size();
        int old = image[sr][sc];
        if (old == newColor) return image;
        image[sr][sc] = newColor;

        while (!q.empty()) {
            pair<int, int> cor = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = cor.first + dr[i];
                int nc = cor.second + dc[i];
                     
                if (nr < 0 || nr >= rlen || nc < 0 || nc >= clen) continue;
                if (image[nr][nc] == old) {
                    image[nr][nc] = newColor;
                    q.emplace(nr, nc);
                }
            }
        } 

        return image;
    }
};