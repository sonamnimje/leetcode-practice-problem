class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        // Min-heap: {height, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        
        int res = 0;
        
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int h = top[0], r = top[1], c = top[2];
            res = max(res, h);  // water must rise to this level
            
            if (r == n - 1 && c == n - 1)
                return res;  // reached destination
            
            for (auto &d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                visited[nr][nc] = 1;
                pq.push({grid[nr][nc], nr, nc});
            }
        }
        return -1; // should never happen
    }
};
