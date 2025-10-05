class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // BFS for Pacific (top row and left column)
        queue<pair<int,int>> q;
        for (int i = 0; i < m; ++i) { pac[i][0] = true; q.emplace(i, 0); }
        for (int j = 1; j < n; ++j) { pac[0][j] = true; q.emplace(0, j); }

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (pac[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue; // can only go to equal/higher
                pac[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }

        // BFS for Atlantic (bottom row and right column)
        for (; !q.empty(); q.pop()); // ensure queue empty (should be already, but safe)
        for (int i = 0; i < m; ++i) { atl[i][n-1] = true; q.emplace(i, n-1); }
        for (int j = 0; j < n-1; ++j) { atl[m-1][j] = true; q.emplace(m-1, j); }

        while (!q.empty()) {
            auto [r,c] = q.front(); q.pop();
            for (auto &d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (atl[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                atl[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }

        // Collect cells reachable by both oceans
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});

        return res;
    }
};
