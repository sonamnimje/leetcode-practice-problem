class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1]; // Sort by end time
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), comp);
        int n = events.size();

        // dp[i][j] = max value by attending at most i events from first j events
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // Extract end times for binary search
        vector<int> ends;
        for (auto& e : events) ends.push_back(e[1]);

        for (int i = 1; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                // Skip event j-1
                dp[i][j] = dp[i][j - 1];

                // Binary search to find last event that ends before events[j-1][0]
                int idx = upper_bound(ends.begin(), ends.end(), events[j - 1][0] - 1) - ends.begin();
                dp[i][j] = max(dp[i][j], dp[i - 1][idx] + events[j - 1][2]);
            }
        }

        return dp[k][n];
    }
};
