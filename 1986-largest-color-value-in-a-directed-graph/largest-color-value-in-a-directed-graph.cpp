class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int processed = 0;
        int maxColorCount = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            processed++;
            int colorIdx = colors[node] - 'a';
            dp[node][colorIdx]++;
            maxColorCount = max(maxColorCount, dp[node][colorIdx]);
            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
                }
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return processed == n ? maxColorCount : -1;
    }
};