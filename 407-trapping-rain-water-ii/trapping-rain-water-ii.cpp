class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // min-heap (priority queue), storing {height, x, y}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Push all boundary cells into heap
        for (int i = 0; i < m; i++) {
            minHeap.push({heightMap[i][0], i, 0});
            minHeap.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 1; j < n-1; j++) {
            minHeap.push({heightMap[0][j], 0, j});
            minHeap.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = true;
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int trapped = 0;

        while (!minHeap.empty()) {
            auto cell = minHeap.top();
            minHeap.pop();

            int h = cell[0], x = cell[1], y = cell[2];

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                // if neighbor is lower, water can be trapped
                if (heightMap[nx][ny] < h) {
                    trapped += h - heightMap[nx][ny];
                }

                // push neighbor with updated boundary height
                minHeap.push({max(h, heightMap[nx][ny]), nx, ny});
            }
        }

        return trapped;
    }
};